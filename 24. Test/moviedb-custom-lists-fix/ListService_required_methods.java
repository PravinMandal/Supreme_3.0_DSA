/*
 * File:
 * backend/src/main/java/com/moviedb/service/ListService.java
 *
 * Add these imports if they are missing:
 *
 * import java.util.ArrayList;
 * import java.util.Objects;
 * import java.util.Optional;
 * import org.springframework.http.HttpStatus;
 * import org.springframework.web.server.ResponseStatusException;
 *
 * Assumed existing fields:
 *
 * private ListRepository listRepository;
 * private MovieRepository movieRepository;
 * private UserRepository userRepository;
 */

public CustomList addMovieToList(String listId, String movieId, String email) {
    if (movieId == null || movieId.isBlank()) {
        throw new ResponseStatusException(HttpStatus.BAD_REQUEST, "Movie ID is required");
    }

    String userId = requireAuthenticatedUserId(email);
    CustomList list = requireOwnedList(listId, userId);

    Movie movie = movieRepository.findById(movieId)
            .orElseThrow(() -> new ResponseStatusException(HttpStatus.NOT_FOUND, "Movie not found"));

    if (list.getMovies() == null) {
        list.setMovies(new ArrayList<>());
    }

    boolean alreadyInList = list.getMovies().stream()
            .anyMatch(existingMovie -> Objects.equals(existingMovie.getId(), movieId));

    if (alreadyInList) {
        throw new ResponseStatusException(HttpStatus.BAD_REQUEST, "Movie already in this list");
    }

    list.getMovies().add(movie);
    return listRepository.save(list);
}

public CustomList removeMovieFromList(String listId, String movieId, String email) {
    String userId = requireAuthenticatedUserId(email);
    CustomList list = requireOwnedList(listId, userId);

    if (list.getMovies() == null) {
        list.setMovies(new ArrayList<>());
    }

    boolean removed = list.getMovies().removeIf(movie -> Objects.equals(movie.getId(), movieId));

    if (!removed) {
        throw new ResponseStatusException(HttpStatus.BAD_REQUEST, "Movie not in this list");
    }

    return listRepository.save(list);
}

private String requireAuthenticatedUserId(String principal) {
    Optional<User> byEmail = userRepository.findByEmail(principal);
    if (byEmail.isPresent()) {
        return byEmail.get().getId();
    }

    return userRepository.findById(principal)
            .map(User::getId)
            .orElseThrow(() -> new ResponseStatusException(HttpStatus.UNAUTHORIZED, "Unauthorized"));
}

private CustomList requireOwnedList(String listId, String userId) {
    CustomList list = listRepository.findById(listId)
            .orElseThrow(() -> new ResponseStatusException(HttpStatus.NOT_FOUND, "List not found"));

    /*
     * The README response shows "user": "user_id", so this is the most likely model.
     * If your project stores User user instead of String user, use:
     * Objects.equals(list.getUser().getId(), userId)
     */
    if (!Objects.equals(list.getUser(), userId)) {
        throw new ResponseStatusException(HttpStatus.NOT_FOUND, "List not found");
    }

    return list;
}

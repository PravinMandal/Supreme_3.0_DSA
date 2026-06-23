/*
 * File:
 * backend/src/main/java/com/moviedb/service/ListService.java
 *
 * Add these imports if they are missing:
 *
 * import java.util.ArrayList;
 * import java.util.Objects;
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
        throw new IllegalArgumentException("Movie ID is required");
    }

    User user = userRepository.findByEmail(email)
            .orElseThrow(() -> new ResponseStatusException(HttpStatus.UNAUTHORIZED, "Unauthorized"));

    CustomList list = listRepository.findById(listId)
            .orElseThrow(() -> new ResponseStatusException(HttpStatus.NOT_FOUND, "List not found"));

    if (!Objects.equals(list.getUser().getId(), user.getId())) {
        throw new ResponseStatusException(HttpStatus.NOT_FOUND, "List not found");
    }

    Movie movie = movieRepository.findById(movieId)
            .orElseThrow(() -> new ResponseStatusException(HttpStatus.NOT_FOUND, "Movie not found"));

    if (list.getMovies() == null) {
        list.setMovies(new ArrayList<>());
    }

    boolean alreadyInList = list.getMovies().stream()
            .anyMatch(existingMovie -> Objects.equals(existingMovie.getId(), movieId));

    if (alreadyInList) {
        throw new IllegalArgumentException("Movie already in this list");
    }

    list.getMovies().add(movie);
    return listRepository.save(list);
}

public CustomList removeMovieFromList(String listId, String movieId, String email) {
    User user = userRepository.findByEmail(email)
            .orElseThrow(() -> new ResponseStatusException(HttpStatus.UNAUTHORIZED, "Unauthorized"));

    CustomList list = listRepository.findById(listId)
            .orElseThrow(() -> new ResponseStatusException(HttpStatus.NOT_FOUND, "List not found"));

    if (!Objects.equals(list.getUser().getId(), user.getId())) {
        throw new ResponseStatusException(HttpStatus.NOT_FOUND, "List not found");
    }

    if (list.getMovies() == null) {
        list.setMovies(new ArrayList<>());
    }

    boolean removed = list.getMovies().removeIf(movie -> Objects.equals(movie.getId(), movieId));

    if (!removed) {
        throw new IllegalArgumentException("Movie not in this list");
    }

    return listRepository.save(list);
}


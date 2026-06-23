import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Optional;

public class SolutionContractTest {
    public static void main(String[] args) {
        shouldAddMovieAndPersistIt();
        shouldRejectMissingMovieId();
        shouldRejectUnknownMovie();
        shouldRejectUnknownList();
        shouldRejectDuplicateMovie();
        shouldRemoveMovieAndPersistIt();
        shouldRejectRemovingMovieNotInList();
        shouldRejectOtherUsersListAsNotFound();

        System.out.println("All contract tests passed.");
    }

    private static void shouldAddMovieAndPersistIt() {
        Fixture fixture = new Fixture();

        CustomList updated = fixture.service.addMovieToList("list-1", "movie-1", "sam.rivera@email.com");

        assertEquals(1, updated.getMovies().size(), "movie count after add");
        assertEquals("movie-1", updated.getMovies().get(0).getId(), "added movie id");
        assertEquals(1, fixture.listRepository.saveCount, "list saved after add");
    }

    private static void shouldRejectMissingMovieId() {
        Fixture fixture = new Fixture();

        assertError(400, "Movie ID is required",
                () -> fixture.service.addMovieToList("list-1", "", "sam.rivera@email.com"));
    }

    private static void shouldRejectUnknownMovie() {
        Fixture fixture = new Fixture();

        assertError(404, "Movie not found",
                () -> fixture.service.addMovieToList("list-1", "missing-movie", "sam.rivera@email.com"));
    }

    private static void shouldRejectUnknownList() {
        Fixture fixture = new Fixture();

        assertError(404, "List not found",
                () -> fixture.service.addMovieToList("missing-list", "movie-1", "sam.rivera@email.com"));
    }

    private static void shouldRejectDuplicateMovie() {
        Fixture fixture = new Fixture();

        fixture.service.addMovieToList("list-1", "movie-1", "sam.rivera@email.com");

        assertError(400, "Movie already in this list",
                () -> fixture.service.addMovieToList("list-1", "movie-1", "sam.rivera@email.com"));
    }

    private static void shouldRemoveMovieAndPersistIt() {
        Fixture fixture = new Fixture();

        fixture.service.addMovieToList("list-1", "movie-1", "sam.rivera@email.com");
        fixture.listRepository.saveCount = 0;

        CustomList updated = fixture.service.removeMovieFromList("list-1", "movie-1", "sam.rivera@email.com");

        assertEquals(0, updated.getMovies().size(), "movie count after remove");
        assertEquals(1, fixture.listRepository.saveCount, "list saved after remove");
    }

    private static void shouldRejectRemovingMovieNotInList() {
        Fixture fixture = new Fixture();

        assertError(400, "Movie not in this list",
                () -> fixture.service.removeMovieFromList("list-1", "movie-1", "sam.rivera@email.com"));
    }

    private static void shouldRejectOtherUsersListAsNotFound() {
        Fixture fixture = new Fixture();

        assertError(404, "List not found",
                () -> fixture.service.addMovieToList("other-user-list", "movie-1", "sam.rivera@email.com"));
    }

    private static void assertError(int expectedStatus, String expectedMessage, Action action) {
        try {
            action.run();
            throw new AssertionError("Expected error " + expectedStatus + " " + expectedMessage);
        } catch (ApiException ex) {
            assertEquals(expectedStatus, ex.status, "status");
            assertEquals(expectedMessage, ex.message, "message");
        }
    }

    private static void assertEquals(Object expected, Object actual, String label) {
        if (!Objects.equals(expected, actual)) {
            throw new AssertionError(label + " expected <" + expected + "> but got <" + actual + ">");
        }
    }

    private interface Action {
        void run();
    }

    private static final class Fixture {
        private final UserRepository userRepository = new UserRepository();
        private final MovieRepository movieRepository = new MovieRepository();
        private final ListRepository listRepository = new ListRepository();
        private final ListService service = new ListService(listRepository, movieRepository, userRepository);

        private Fixture() {
            userRepository.usersByEmail.put("sam.rivera@email.com", new User("user-1", "sam.rivera@email.com"));
            userRepository.usersByEmail.put("other@email.com", new User("user-2", "other@email.com"));

            movieRepository.movies.put("movie-1", new Movie("movie-1", "Interstellar"));

            listRepository.lists.put("list-1", new CustomList("list-1", "My Favorite Action Movies", "user-1"));
            listRepository.lists.put("other-user-list", new CustomList("other-user-list", "Other List", "user-2"));
        }
    }

    private static final class ListService {
        private final ListRepository listRepository;
        private final MovieRepository movieRepository;
        private final UserRepository userRepository;

        private ListService(ListRepository listRepository, MovieRepository movieRepository, UserRepository userRepository) {
            this.listRepository = listRepository;
            this.movieRepository = movieRepository;
            this.userRepository = userRepository;
        }

        private CustomList addMovieToList(String listId, String movieId, String email) {
            if (movieId == null || movieId.isBlank()) {
                throw new ApiException(400, "Movie ID is required");
            }

            String userId = requireAuthenticatedUserId(email);
            CustomList list = requireOwnedList(listId, userId);

            Movie movie = movieRepository.findById(movieId)
                    .orElseThrow(() -> new ApiException(404, "Movie not found"));

            if (list.getMovies() == null) {
                list.setMovies(new ArrayList<>());
            }

            boolean alreadyInList = list.getMovies().stream()
                    .anyMatch(existingMovie -> Objects.equals(existingMovie.getId(), movieId));

            if (alreadyInList) {
                throw new ApiException(400, "Movie already in this list");
            }

            list.getMovies().add(movie);
            return listRepository.save(list);
        }

        private CustomList removeMovieFromList(String listId, String movieId, String email) {
            String userId = requireAuthenticatedUserId(email);
            CustomList list = requireOwnedList(listId, userId);

            if (list.getMovies() == null) {
                list.setMovies(new ArrayList<>());
            }

            boolean removed = list.getMovies().removeIf(movie -> Objects.equals(movie.getId(), movieId));

            if (!removed) {
                throw new ApiException(400, "Movie not in this list");
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
                    .orElseThrow(() -> new ApiException(401, "Unauthorized"));
        }

        private CustomList requireOwnedList(String listId, String userId) {
            CustomList list = listRepository.findById(listId)
                    .orElseThrow(() -> new ApiException(404, "List not found"));

            if (!Objects.equals(list.getUser(), userId)) {
                throw new ApiException(404, "List not found");
            }

            return list;
        }
    }

    private static final class ListRepository {
        private final Map<String, CustomList> lists = new HashMap<>();
        private int saveCount;

        private Optional<CustomList> findById(String id) {
            return Optional.ofNullable(lists.get(id));
        }

        private CustomList save(CustomList list) {
            saveCount++;
            lists.put(list.getId(), list);
            return list;
        }
    }

    private static final class MovieRepository {
        private final Map<String, Movie> movies = new HashMap<>();

        private Optional<Movie> findById(String id) {
            return Optional.ofNullable(movies.get(id));
        }
    }

    private static final class UserRepository {
        private final Map<String, User> usersByEmail = new HashMap<>();

        private Optional<User> findByEmail(String email) {
            return Optional.ofNullable(usersByEmail.get(email));
        }

        private Optional<User> findById(String id) {
            return usersByEmail.values().stream()
                    .filter(user -> Objects.equals(user.getId(), id))
                    .findFirst();
        }
    }

    private static final class CustomList {
        private final String id;
        private final String name;
        private final String user;
        private List<Movie> movies = new ArrayList<>();

        private CustomList(String id, String name, String user) {
            this.id = id;
            this.name = name;
            this.user = user;
        }

        private String getId() {
            return id;
        }

        private String getName() {
            return name;
        }

        private String getUser() {
            return user;
        }

        private List<Movie> getMovies() {
            return movies;
        }

        private void setMovies(List<Movie> movies) {
            this.movies = movies;
        }
    }

    private static final class Movie {
        private final String id;
        private final String title;

        private Movie(String id, String title) {
            this.id = id;
            this.title = title;
        }

        private String getId() {
            return id;
        }

        private String getTitle() {
            return title;
        }
    }

    private static final class User {
        private final String id;
        private final String email;

        private User(String id, String email) {
            this.id = id;
            this.email = email;
        }

        private String getId() {
            return id;
        }

        private String getEmail() {
            return email;
        }
    }

    private static final class ApiException extends RuntimeException {
        private final int status;
        private final String message;

        private ApiException(int status, String message) {
            super(message);
            this.status = status;
            this.message = message;
        }
    }
}


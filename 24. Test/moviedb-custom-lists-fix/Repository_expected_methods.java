/*
 * Existing Spring Data repositories should already provide these methods.
 * Do not add custom repository methods unless your current code lacks user lookup by email.
 */

public interface ListRepository extends MongoRepository<CustomList, String> {
}

public interface MovieRepository extends MongoRepository<Movie, String> {
}

public interface UserRepository extends MongoRepository<User, String> {
    Optional<User> findByEmail(String email);
}


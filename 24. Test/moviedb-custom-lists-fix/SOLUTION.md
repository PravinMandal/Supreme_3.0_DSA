# MovieDB Custom Lists Backend Fix - Spring Boot

## Root Cause Analysis

The custom list creation flow works, but adding a movie to a list does not persist the relationship between the selected list and the selected movie.

The bug belongs in the backend list-movie flow:

- `POST /api/lists/{listId}/movies`
- `DELETE /api/lists/{listId}/movies/{movieId}`

The expected execution flow is:

1. Controller receives the authenticated request.
2. Controller validates required request data.
3. Service loads the list owned by the authenticated user.
4. Service loads the movie by ID.
5. Service adds or removes the movie from the list's `movies` collection.
6. Service saves the updated list through the repository.
7. Controller returns the documented response shape.

The failure occurs when step 5 or step 6 is missing or incorrect. In that case, the UI can show the list in the dropdown, but after navigating back to "Your Lists", the movie is not present because the list document was never updated and saved.

## Files That Must Be Changed

Only these backend files need changes:

- `backend/src/main/java/com/moviedb/controller/ListController.java`
  - Must expose the add/remove movie endpoints with the documented response messages and error responses.

- `backend/src/main/java/com/moviedb/service/ListService.java`
  - Must implement the actual database update: validate IDs, find the list, find the movie, prevent duplicates, add/remove the movie, and save the list.

## Files That Must NOT Be Changed

These may look related, but they should stay untouched for a minimal fix:

- `MovieController.java`
  - Movie detail pages are not broken.

- `MovieRepository.java`
  - Existing movie lookup is enough.

- `ListRepository.java`
  - Existing `findById` and `save` are enough unless the project already has an owner-scoped query.

- `CustomList` / list entity model
  - The model already supports a `movies` collection because lists can display movies.

- Security configuration
  - Auth is already required for custom lists.

- Frontend files
  - The UI sends the request and only fails because the backend does not persist the update.

## Acceptance Criteria Covered

- Add movie to custom list.
- Remove movie from custom list.
- Return documented success messages.
- Return `400` when `movieId` is missing.
- Return `404` when the list is missing.
- Return `404` when the movie is missing.
- Return `400` when the movie is already in the list.
- Return `400` when removing a movie that is not in the list.
- Persist the updated list with `listRepository.save(list)`.
- Keep authenticated users limited to their own lists.

## Spring Boot Notes

This solution assumes a typical Spring Boot backend with:

- `CustomList` entity/document containing `id`, `name`, `description`, `user`, and `List<Movie> movies`.
- `Movie` entity/document containing `id`.
- `User` entity/document containing `id` and `email`.
- `ListRepository`, `MovieRepository`, and `UserRepository` extending Spring Data repositories.
- JWT or session authentication already configured so `Authentication#getName()` returns the logged-in user's email.

If your project uses MongoDB, the same service logic works with `MongoRepository`.
If your project uses JPA, ensure the list/movie relationship is mapped in the existing `CustomList` entity.

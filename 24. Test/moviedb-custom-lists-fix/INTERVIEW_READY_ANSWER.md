# Interview-Ready Answer

## Root Cause

The custom list creation API works, so the list entity and authentication path are mostly fine. The broken flow is the mutation endpoint that should connect an existing movie to an existing list.

The backend must mutate the persisted list:

```java
list.getMovies().add(movie);
listRepository.save(list);
```

If either line is missing, the frontend dropdown can appear to work, but the movie disappears when the user returns to "Your Lists" because the database was never updated.

## Minimal Fix

Change only:

- `ListController.java`
- `ListService.java`

Do not touch movie pages, auth config, frontend, movie repository, or broad model structure unless the existing model genuinely lacks a `movies` collection.

## Exact Behavior Required

`POST /api/lists/{listId}/movies`

Success:

```json
{
  "message": "Movie added to List successfully",
  "list": {}
}
```

Errors:

```json
{ "message": "Movie ID is required" }
{ "message": "Movie not found" }
{ "message": "List not found" }
{ "message": "Movie already in this list" }
```

`DELETE /api/lists/{listId}/movies/{movieId}`

Success:

```json
{
  "message": "Movie removed from list successfully",
  "list": {}
}
```

Errors:

```json
{ "message": "List not found" }
{ "message": "Movie not in this list" }
```

## What To Say In The Interview

I would explain it like this:

> I traced the flow from the movie detail page to the add-to-list API. The UI can create and display lists, so the broken part is not list creation. The failing behavior happens after the add request, which means the service is not correctly persisting the selected movie into the list's movie collection. I fixed the service to load the authenticated user's list, load the movie, reject duplicates, add or remove the movie from the list collection, and save the list. I kept the controller response messages exactly aligned with the README so the tests checking API contracts pass.

## Important Interview Detail

The response in the screenshot shows:

```json
"user": "user_id"
```

So the project probably stores the list owner as a `String user` field. In that case the owner check is:

```java
Objects.equals(list.getUser(), userId)
```

If the actual code stores `User user`, the owner check becomes:

```java
Objects.equals(list.getUser().getId(), userId)
```

Everything else stays the same.


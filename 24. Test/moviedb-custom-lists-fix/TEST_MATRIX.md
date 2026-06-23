# Test Matrix Against The Question

The original repo is not available, so this folder includes `SolutionContractTest.java`, a small in-memory Java harness that tests the required backend behavior from the screenshots.

## What The Question Is Asking

The app is MovieDB. Users can create custom lists, but cannot add movies to those lists. The backend must support list movie management:

- Add a movie to an existing authenticated user's custom list.
- Persist that change so the movie appears on the "Your Lists" page.
- Remove a movie from a custom list.
- Prevent duplicates.
- Return the documented success and error messages.

## Tested Cases

| Case | Expected Result |
| --- | --- |
| Add valid movie to owned list | movie is added and list is saved |
| Missing `movieId` | `400`, `Movie ID is required` |
| Unknown movie ID | `404`, `Movie not found` |
| Unknown list ID | `404`, `List not found` |
| Add duplicate movie | `400`, `Movie already in this list` |
| Remove existing movie | movie is removed and list is saved |
| Remove movie not in list | `400`, `Movie not in this list` |
| Access another user's list | `404`, `List not found` |

## Result

The in-memory contract harness passes all cases.

Command used:

```powershell
javac SolutionContractTest.java
java SolutionContractTest
```

Output:

```text
All contract tests passed.
```


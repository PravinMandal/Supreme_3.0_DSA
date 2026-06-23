/*
 * File:
 * backend/src/main/java/com/moviedb/controller/ListController.java
 *
 * Add these imports if they are missing:
 *
 * import java.util.Map;
 * import org.springframework.http.HttpStatus;
 * import org.springframework.http.ResponseEntity;
 * import org.springframework.security.core.Authentication;
 * import org.springframework.web.bind.annotation.DeleteMapping;
 * import org.springframework.web.bind.annotation.PathVariable;
 * import org.springframework.web.bind.annotation.PostMapping;
 * import org.springframework.web.bind.annotation.RequestBody;
 * import org.springframework.web.server.ResponseStatusException;
 */

@PostMapping("/{listId}/movies")
public ResponseEntity<?> addMovieToList(
        @PathVariable String listId,
        @RequestBody(required = false) Map<String, String> request,
        Authentication authentication) {
    try {
        String movieId = request == null ? null : request.get("movieId");
        CustomList updatedList = listService.addMovieToList(listId, movieId, authentication.getName());

        return ResponseEntity.ok(Map.of(
                "message", "Movie added to List successfully",
                "list", updatedList));
    } catch (ResponseStatusException ex) {
        return ResponseEntity
                .status(ex.getStatusCode())
                .body(Map.of("message", ex.getReason()));
    } catch (IllegalArgumentException ex) {
        return ResponseEntity
                .status(HttpStatus.BAD_REQUEST)
                .body(Map.of("message", ex.getMessage()));
    }
}

@DeleteMapping("/{listId}/movies/{movieId}")
public ResponseEntity<?> removeMovieFromList(
        @PathVariable String listId,
        @PathVariable String movieId,
        Authentication authentication) {
    try {
        CustomList updatedList = listService.removeMovieFromList(listId, movieId, authentication.getName());

        return ResponseEntity.ok(Map.of(
                "message", "Movie removed from list successfully",
                "list", updatedList));
    } catch (ResponseStatusException ex) {
        return ResponseEntity
                .status(ex.getStatusCode())
                .body(Map.of("message", ex.getReason()));
    } catch (IllegalArgumentException ex) {
        return ResponseEntity
                .status(HttpStatus.BAD_REQUEST)
                .body(Map.of("message", ex.getMessage()));
    }
}


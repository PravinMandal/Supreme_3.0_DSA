/*
 * File:
 * backend/src/main/java/com/moviedb/controller/ListController.java
 *
 * Replace/add only these methods inside the existing ListController.
 * Assumes the class already has:
 *
 * @RequestMapping("/api/lists")
 * private ListService listService;
 *
 * Add these imports if they are missing:
 *
 * import java.util.Map;
 * import org.springframework.http.ResponseEntity;
 * import org.springframework.security.core.Authentication;
 * import org.springframework.web.bind.annotation.DeleteMapping;
 * import org.springframework.web.bind.annotation.PathVariable;
 * import org.springframework.web.bind.annotation.PostMapping;
 * import org.springframework.web.bind.annotation.RequestBody;
 * import org.springframework.web.server.ResponseStatusException;
 */

@PostMapping("/{listId}/movies")
public ResponseEntity<Map<String, Object>> addMovieToList(
        @PathVariable String listId,
        @RequestBody(required = false) Map<String, Object> request,
        Authentication authentication) {
    try {
        Object rawMovieId = request == null ? null : request.get("movieId");
        String movieId = rawMovieId == null ? null : rawMovieId.toString();
        CustomList updatedList = listService.addMovieToList(listId, movieId, authentication.getName());

        return ResponseEntity.ok(Map.of(
                "message", "Movie added to List successfully",
                "list", updatedList));
    } catch (ResponseStatusException ex) {
        return listError(ex);
    }
}

@DeleteMapping("/{listId}/movies/{movieId}")
public ResponseEntity<Map<String, Object>> removeMovieFromList(
        @PathVariable String listId,
        @PathVariable String movieId,
        Authentication authentication) {
    try {
        CustomList updatedList = listService.removeMovieFromList(listId, movieId, authentication.getName());

        return ResponseEntity.ok(Map.of(
                "message", "Movie removed from list successfully",
                "list", updatedList));
    } catch (ResponseStatusException ex) {
        return listError(ex);
    }
}

private ResponseEntity<Map<String, Object>> listError(ResponseStatusException ex) {
    String message = ex.getReason() == null ? "Request failed" : ex.getReason();
    return ResponseEntity
            .status(ex.getStatusCode())
            .body(Map.<String, Object>of("message", message));
}

/*
 * File:
 * backend/src/main/java/com/moviedb/model/CustomList.java
 *
 * Do NOT replace your whole model if it already exists.
 * This shows only the fields/getters/setters the fix expects.
 */

private String id;
private String name;
private String description;
private User user;
private List<Movie> movies = new ArrayList<>();

public String getId() {
    return id;
}

public User getUser() {
    return user;
}

public List<Movie> getMovies() {
    return movies;
}

public void setMovies(List<Movie> movies) {
    this.movies = movies;
}


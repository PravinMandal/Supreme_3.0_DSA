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
private String user;
private List<Movie> movies = new ArrayList<>();

public String getId() {
    return id;
}

public String getUser() {
    return user;
}

public List<Movie> getMovies() {
    return movies;
}

public void setMovies(List<Movie> movies) {
    this.movies = movies;
}

/*
 * If the real project stores an embedded/reference User instead:
 *
 * private User user;
 *
 * then keep that existing model and change only the service owner check to:
 *
 * Objects.equals(list.getUser().getId(), userId)
 */

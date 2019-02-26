package koreatech.cse.domain;

public class Book {
    private int id;
    private String name;
    private String issn;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getIssn() {
        return issn;
    }

    public void setIssn(String issn) {
        this.issn = issn;
    }

    @Override
    public String toString() {
        return "id: " + id + ", name: " + name
                + ", issn: " + issn;
    }
}

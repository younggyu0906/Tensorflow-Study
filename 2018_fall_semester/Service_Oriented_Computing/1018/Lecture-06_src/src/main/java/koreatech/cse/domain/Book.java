package koreatech.cse.domain;

public class Book {
    private int id;
    private String bookName;
    private String issn;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getBookName() { return bookName; }

    public void setBookName(String bookName) { this.bookName = bookName; }

    public String getIssn() { return issn; }

    public void setIssn(String issn) { this.issn = issn; }

    @Override
    public String toString() {
        return "id: " + id + ", bookName: " + bookName
                + ", issn: " + issn;
    }

}

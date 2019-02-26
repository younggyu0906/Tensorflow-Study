package koreatech.cse.domain;

import java.util.Date;

public class Board {
    private int id;
    private String subject;
    private String contents;
    private Date regdate;
    private int hits;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getSubject() {
        return subject;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }

    public String getContents() {
        return contents;
    }

    public void setContents(String contents) {
        this.contents = contents;
    }

    public Date getRegdate() {
        return regdate;
    }

    public void setRegdate(Date regdate) {
        this.regdate = regdate;
    }

    public int getHits() {
        return hits;
    }

    public void setHits(int hits) {
        this.hits = hits;
    }

    @Override
    public String toString() {
        return "id: " + id + ", subject: " + subject
                + ", contents: " + contents + ", regdate: " + regdate + ", hits: " + hits;
    }
}

package koreatech.cse.domain;

public class User {
    private int id;
    private String name;
    private String email;
    private String password;
    private int age;
    private String phone;
    private Book book;

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

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getPhone() { return  phone; }

    public  void setPhone(String phone) { this.phone = phone; }

    public Book getBook() { return book; }

    public void setBook(Book book) { this.book = book; }

    @Override
    public String toString() {
        return "id: " + id + ", name: " + name
                + ", email: " + email + ", password: " + password + ", age: " + age + ", phone: " + phone;
    }
}

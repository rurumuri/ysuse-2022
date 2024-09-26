
package com.al_1suyan.domain;

import org.hibernate.annotations.Type;
import org.springframework.format.annotation.DateTimeFormat;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import java.util.Date;
@Entity
public class Student {
    @Id
    @GeneratedValue
    private Integer id;
    private String username;
    private String password;
    @DateTimeFormat(pattern="yyyy-MM-dd")
    @Type(type = "date")
    private Date birthday;
    private String phone;
    public Student(Integer id, String username, String password, Date birthday, String phone) {
        this.id = id;
        this.username = username;
        this.password = password;
        this.birthday = birthday;
        this.phone = phone;
    }

    public Student() {}

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public Date getBirthday() {
        return birthday;
    }

    public void setBirthday(Date birthday) {
        this.birthday = birthday;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", birthday=" + birthday +
                ", phone='" + phone + '\'' +
                '}';
    }
}

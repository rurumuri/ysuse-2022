package com.al_1suyan.pojo;

public class User {
    private String username;//用户账号
    private String password;//用户密码
    private int uid;

    public User() {
    }

    public User(String username, String password) {
        this.username = username;
        this.password = password;
        //this.uid = uid;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public int getUid() {
        return uid;
    }
}

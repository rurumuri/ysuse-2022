package com.al_1suyan.service;

import com.al_1suyan.pojo.User;

import java.util.List;

public interface UserService {
    int add(User user);

    int delete(User user);

    int update(User user);

    List<User> list();

    User getUserByUsername(String username);

    User getUserByUser(User user);

    List<User> query(String keyword);
}

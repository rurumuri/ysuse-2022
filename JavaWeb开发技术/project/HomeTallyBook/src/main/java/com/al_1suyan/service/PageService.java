package com.al_1suyan.service;

import java.util.List;

public interface PageService<E> {
    List<E> getUsers(int page);

    List<Integer> getList(int page);
}

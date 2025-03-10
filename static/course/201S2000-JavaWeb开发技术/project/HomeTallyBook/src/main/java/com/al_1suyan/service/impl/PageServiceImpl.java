package com.al_1suyan.service.impl;

import com.al_1suyan.service.PageService;
import com.al_1suyan.utils.PageDisplay;

import java.util.ArrayList;
import java.util.List;

public class PageServiceImpl<E> implements PageService<E> {
    PageDisplay<E> pageDisplay;

    public PageServiceImpl(PageDisplay<E> pageDisplay) {
        this.pageDisplay = pageDisplay;
    }

    public List<E> getUsers(int page) {
        List<E> homeCosts = new ArrayList<>();
        for (int i = (page - 1) * pageDisplay.getMaxNumOnePage(); i < pageDisplay.getElement().size() && i < page * pageDisplay.getMaxNumOnePage(); i++) {
            homeCosts.add(pageDisplay.getElement().get(i));
        }
        return homeCosts;
    }

    public List<Integer> getList(int page) {
        List<Integer> integerList = new ArrayList<>();
        int left = 1;
        int right = 1;
        if (pageDisplay.getSize() >= 1 && pageDisplay.getSize() <= 5) {
            for (Integer integer = 1; integer <= pageDisplay.getSize(); integer++) {
                integerList.add(integer);
            }
        } else if (page <= 2) {
            //这里就是一页能够分五页 - - - - - -
            for (Integer integer = 1; integer <= 5; integer++) {
                integerList.add(integer);
            }
        } else if (page + 2 > pageDisplay.getSize()) {
            for (Integer integer = pageDisplay.getSize() - 4; integer <= pageDisplay.getSize(); integer++) {
                integerList.add(integer);
            }
        } else {
            for (Integer integer = page - 2; integer <= pageDisplay.getSize() && integer <= page + 2; integer++) {
                integerList.add(integer);
            }
        }
        return integerList;
    }
}

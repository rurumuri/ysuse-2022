package com.al_1suyan.service;

import com.al_1suyan.pojo.HomeCost;

import java.util.List;

public interface HomeCostService {
    int add(HomeCost homecost, int uid);

    int delete(int id);

    int update(HomeCost homecost);

    List<HomeCost> query(String keyword);

    List<HomeCost> list(int uid);

    HomeCost getHomeCostById(int id);
}

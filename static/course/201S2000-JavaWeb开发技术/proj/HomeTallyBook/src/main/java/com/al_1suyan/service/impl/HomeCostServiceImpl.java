package com.al_1suyan.service.impl;

import com.al_1suyan.dao.HomeCostDao;
import com.al_1suyan.pojo.HomeCost;
import com.al_1suyan.service.HomeCostService;

import java.util.List;

public class HomeCostServiceImpl implements HomeCostService {
    private int uid;

    HomeCostDao homeCostDao;

    public HomeCostServiceImpl(int uid) {
        // TODO Auto-generated constructor stub
        this.uid = uid;
        this.homeCostDao = new HomeCostDao(uid);
    }

    public int add(HomeCost homecost, int uid) {
        return homeCostDao.add(homecost, uid);
    }

    public int delete(int id) {
        return homeCostDao.delete(id);
    }

    public int update(HomeCost homecost) {
        return homeCostDao.update(homecost);
    }

    public List<HomeCost> query(String keyword) {
        return homeCostDao.query(keyword);
    }

    public List<HomeCost> list(int uid) {
        return homeCostDao.list(uid);
    }

    public HomeCost getHomeCostById(int id) {
        return homeCostDao.getHomeCostById(id);
    }

}

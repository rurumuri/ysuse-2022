package com.al_1suyan.service.impl;

import com.al_1suyan.pojo.Admin;
import com.al_1suyan.service.AdminService;
import com.al_1suyan.utils.DBUtils;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class AdminServiceImpl implements AdminService {
    public Admin select(Admin admin) {
        String query = String.format("select * from admin where username='%s' and password='%s'", admin.getUsername(), admin.getPassword());
        Admin admin1 = null;
        Connection connection = DBUtils.getConn();
        Statement statement = null;
        ResultSet resultSet = null;
        try {
            statement = connection.createStatement();
            resultSet = statement.executeQuery(query);
            if (resultSet.next()) {
                admin1 = new Admin(resultSet.getString("username"), resultSet.getString("password"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(resultSet, statement, connection);
        }
        return admin1;
    }

    public int update(Admin admin) {
        Connection conn = DBUtils.getConn();//获取连接对象
        Statement state = null;
        String query = String.format("update admin set password='%s' where username='%s'", admin.getPassword(), admin.getUsername());
        try {
            state = conn.createStatement();
            return state.executeUpdate(query);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            DBUtils.close(state, conn);
        }
        return -1;
    }
}

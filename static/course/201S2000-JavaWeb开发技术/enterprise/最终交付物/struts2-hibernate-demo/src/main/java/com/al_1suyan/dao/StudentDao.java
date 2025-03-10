package com.al_1suyan.dao;

import com.al_1suyan.domain.Student;

import java.util.List;

public interface StudentDao {
    Student findByUsername(String username);
    List<Student> list(String username);
    boolean add(Student student);
    Student findById(int id);
    boolean update(Student student);
    boolean delete(Student student);
}

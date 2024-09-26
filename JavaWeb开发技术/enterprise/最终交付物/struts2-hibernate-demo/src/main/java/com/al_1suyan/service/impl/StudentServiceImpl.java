package com.al_1suyan.service.impl;

import com.al_1suyan.dao.StudentDao;
import com.al_1suyan.dao.impl.StudentDaoImpl;
import com.al_1suyan.domain.Student;
import com.al_1suyan.service.StudentService;

import java.util.List;

public class StudentServiceImpl implements StudentService {
    private StudentDao studentDao =new StudentDaoImpl();

    @Override
    public Student findByUsername(String username) {
        return studentDao.findByUsername(username);
    }
    @Override
    public List<Student> list(String username) {
        return studentDao.list(username);
    }
    @Override
    public boolean add(Student student) {
        return studentDao.add(student);
    }
    @Override
    public Student findById(int id) {
        return studentDao.findById(id);
    }
    @Override
    public boolean update(Student student) {
        return studentDao.update(student);
    }
    @Override
    public boolean delete(Student student) {
        return studentDao.delete(student);
    }
}

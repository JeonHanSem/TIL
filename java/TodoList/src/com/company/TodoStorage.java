package com.company;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by coupang on 2017. 1. 15..
 */
public interface TodoStorage {
    Map<Integer, Todo> todoList = new HashMap<>();
}

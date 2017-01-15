package com.company;

import java.util.ArrayList;
import java.util.List;

/**
 * 데이터를 처리하기위한 저장소
 */
public class Lumberroom implements TodoStorage{
    private int todoIdx;

    public Lumberroom(){
        this.todoIdx = todoList.size()+1;
    }

    public Lumberroom(int todoIdx) {
        this.todoIdx = todoIdx;
    }

    public void saveTodo(Todo todo,int state){
        todo.setTodoIdx(todoIdx);
        todo.setState(state);
        todoList.put(todo.getTodoIdx(),todo);
    }

    public Todo loadTodo(int todoIdx){
        return todoList.get(todoIdx);
    }

    public List<Todo> listTodo(int state){
        List<Todo> list = new ArrayList<>();
        for(int i=1;i<=todoList.size();i++){
            if(state == todoList.get(i).getState()){
                list.add(todoList.get(i));
            }
        }
        return list;
    }
}
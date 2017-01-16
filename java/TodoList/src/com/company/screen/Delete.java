package com.company.screen;

import com.company.Lumberroom;
import com.company.ViewController;

/**
 * Created by coupang on 2017. 1. 16..
 */
public class Delete extends ViewController implements View, Setting {
    private int todoIdx;

    Delete(int todoIdx) {
        this.todoIdx = todoIdx;
    }

    @Override
    public void printView() {
        try {
            setting();
            System.out.println("---------------\n삭제되었습니다\n---------------");
        }catch (NullPointerException e){
            System.out.println("삭제에 실패하였습니다");
        }
        View yet = new Yet();
        print(yet);
    }

    @Override
    public void setting() {
        Lumberroom lumberroom = new Lumberroom();
        lumberroom.deleteTodo(todoIdx);
    }
}

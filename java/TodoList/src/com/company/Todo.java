package com.company;

/**
 * Todo 객체
 */
public class Todo {
    private int todoIdx;
    private String title;
    private String content;
    private String createDate;
    private String modifyDate;
    private String completeDate;
    private String deadLine;
    // yet = 0, done = 1
    private int state;

    public int getTodoIdx() {
        return todoIdx;
    }

    public void setTodoIdx(int todoIdx) {
        this.todoIdx = todoIdx;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getCreateDate() {
        return createDate;
    }

    public void setCreateDate(String createDate) {
        this.createDate = createDate;
    }

    public String getModifyDate() { return modifyDate; }

    public void setModifyDate(String modifyDate) { this.modifyDate = modifyDate; }

    public String getCompleteDate() {
        return completeDate;
    }

    public void setCompleteDate(String completeDate) {
        this.completeDate = completeDate;
    }

    public String getDeadLine() {
        return deadLine;
    }

    public void setDeadLine(String deadLine) {
        this.deadLine = deadLine;
    }

    public int getState() {
        return state;
    }

    public void setState(int state) {
        this.state = state;
    }
}

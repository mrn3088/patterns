#include <bits/stdc++.h>
// forward declaration
class BoardObserver;
class UIObserver;
// interfaces...
class BoardSubject
{
public:
    virtual void registerObserver(BoardObserver *bo) = 0;
    virtual void notify() = 0;
    std::vector<BoardObserver *> observers;
};

class BoardObserver
{
public:
    virtual void onBoardChanged() = 0;
};

class UISubject
{
public:
    virtual void registerObserver(UIObserver *ub) = 0;
    virtual void notify() = 0;
    std::vector<UIObserver *> observers;
};

class UIObserver
{
public:
    virtual void onUIChanged() = 0;
};

// concrete classes...
class Board : public BoardSubject
{
public:
    virtual void registerObserver(BoardObserver *bo) override
    {
        observers.push_back(bo);
    }
    virtual void notify() override
    {
        for (const auto &o : observers)
        {
            o->onBoardChanged();
        }
    }
    void update()
    {
        std::cout << "Board updated" << std::endl;
    }
};

class UI : public UISubject
{
public:
    virtual void registerObserver(UIObserver *ub) override
    {
        observers.push_back(ub);
    }
    virtual void notify() override
    {
        for (const auto &o : observers)
        {
            o->onUIChanged();
        }
    }
    void update()
    {
        std::cout << "UI updated" << std::endl;
    }
};

class Presenter : public UIObserver, BoardObserver
{
public:
    Board *board;
    UI *ui;
    Presenter(Board *board, UI *ui) : board(board), ui(ui)
    {
        board->registerObserver(this);
        ui->registerObserver(this);
    }

    void onBoardChanged() override
    {
        ui -> update();
    }

    void onUIChanged() override
    {
        board -> update();
    }
};

#pragma once
#include <iostream>
#include "Node.h"

class QueueItem
{
public:
    Node* value;
    QueueItem* next;

    QueueItem(Node* node)
    {
        value = node;
        next = NULL;
    }
};


class NodeQueue {
public:
    QueueItem* head;
    QueueItem* tail;

    NodeQueue()
    {
        head = NULL;
        tail = NULL;
    }

    bool empty()
    {
        return (head == NULL);
    }

    void push(Node* node)
    {
        QueueItem* newItem = new QueueItem(node);

        if (empty()) {
            head = newItem;
            tail = newItem;
            return;
        }

        tail->next = newItem;
        tail = newItem;
        return;
    }

    Node* front()
    {
        return head->value;
    }

    void pop()
    {
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
    }
};
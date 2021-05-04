#pragma once
#include <iostream>
#include "Vertex.h"

class VertexQueueItem
{
public:
    Vertex* value;
    VertexQueueItem* next;

    VertexQueueItem(Vertex* vertex)
    {
        value = vertex;
        next = NULL;
    }
};


class VertexQueue {
public:
    VertexQueueItem* head;
    VertexQueueItem* tail;

    VertexQueue()
    {
        head = NULL;
        tail = NULL;
    }

    bool empty()
    {
        return (head == NULL);
    }

    void push(Vertex* vertex)
    {
        VertexQueueItem* newItem = new VertexQueueItem(vertex);

        if (empty()) {
            head = newItem;
            tail = newItem;
            return;
        }

        tail->next = newItem;
        tail = newItem;
        return;
    }

    Vertex* front()
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
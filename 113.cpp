#include <bits/stdc++.h>
#include <complex.h>
#include <stdio.h> // for c
#include <stdlib.h> // for c
#include <cstdlib> // malloc & free
// fast-io: 
//ios::sync_with_stdio(0);
//cin.tie(0);

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;


int main()
{
    int N, k, m; // N is the number of people, k ccw movement, m cw movement
    std::vector<std::string> results; // holds the results

    scanf("%d %d %d", &N, &k, &m); // scan in initial results

    // init head node (only once ) 
    Node *head = (Node *)malloc(sizeof(Node *));
    head->data = 1;
    head->prev = NULL;

    Node *last_node_buf = head; // holds the previous data on one
    printf("DEBUG: head node added with value 1\n");

    while(N != 0 && k != 0 && m != 0)
    {
        // GENERATE CIRCULAR LIST (of size N) // 
        // last node buffer for changes 
        

        for(int i = 2; i < N + 1; i++)
        {
            Node *new_node = (Node *)malloc(sizeof(Node *)); // allocate memory for the new node 
            new_node->data = i; // set its data to the right one 
            new_node->prev = last_node_buf;
            new_node->next = NULL;

            printf("DEBUG: new node created with value %d and previous value of %d\n", new_node->data, new_node->prev->data);

           last_node_buf = new_node; // reset the last node to be the new node 
        }

        // link head and end node
        last_node_buf->next = head;
        head->prev = last_node_buf;
        printf("The value of the one after last_node (of value %d) is %d, value of one before head is %d, and N value is %d", last_node_buf->data, last_node_buf->next->data, head->prev->data, N);
        // GENERATE CIRCULAR LIST (of size N) // 

        Node *k_node = head->next, *m_node = head->prev; // moves start @ head 
        bool done = false; int ll_size = N;
        // one move (removing both selections)
        while(!done)
        {
            // base cases
            if(N == 0) { done = true; }
            else if(N == 1)
            {
                char result[10]; std::sprintf(result, "  %d", k_node->data);
                results.emplace_back(result);
                done = true;
            }
            else if(N == 2)
            {
                if(k_node != m_node)
                {
                    char result[10];
                    std::sprintf(result, "  %d  %d", k_node->data, m_node->data);
                    results.emplace_back(result);
                    done = true;
                }
            }
            else // N >= 3
            {
                // do normal moves
                for(int i = 0; i < k; i++) { k_node = k_node->next; } // move to k selection
                for(int i = 0; i < m; i++) { m_node = m_node->prev; } // move to m selection
            
                // case: if the same
                if(k_node == m_node)
                {
                    char result[10];
                    std::sprintf(result, "%d ", k_node->data);
                    results.emplace_back(result);
                    k_node = k_node->next; //  move k node up

                    last_node_buf = m_node; // save node selected / removed
                    m_node = m_node->prev; // move m back
                    // connect two nodes together
                    k_node->prev = m_node;
                    m_node->next = k_node;
                    // freeing the memory of deleted node
                    //free(last_node_buf);
                }
                else if(k_node != m_node)
                {
                    char result[10];
                    std::sprintf(result, "  %d  %d,", k_node->data, m_node->data);
                    results.emplace_back(result);
                    k_node = k_node->next;
                    // next to each other case
                    if(k_node == m_node)
                    {
                        k_node = k_node->next;
                        m_node = m_node->prev->prev;
                    }
                }
            }
            N--;
        }         
        scanf("%d %d %d", &N, &k, &m); // scan in next results 
    }
    return 0; // default end if nothing happens 
}
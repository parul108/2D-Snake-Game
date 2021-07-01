#include "snake.h"

int x, y;
// snake - array of coordinates
// will array work fine here?
// No i can't use array
// 10 , 10
// 10 , 11
vector < pair<int , int > > body; // x - body[i][0] , y - body[i][1]
// {1 , 2}    body[0]
// { 2 , 3 }    body[1]
// {10 , 10}    body[2]
// make_pair(,);
// ###
/*
    ###### ->
    #
  ###  
*/

// ###
void init_snake(){
    body.clear();
    body.push_back({10,10});        
    body.push_back({10,11});
    body.push_back({10,12});
}

void paint_snake(){
    for(int i =0 ; i < body.size(); i ++){
        pair < int , int > location = body[i];
        move(location.first, location.second);

        // move(body[i].first , body[i].second);
        addch('#');
    }
}
 
/*
####### ->
 ####### 
modifying every corrdinate actually fails
    ###### ->
    #
 #### 
*/ 
pair < int , int > snake_tail;
pair < int , int > move_snake(int direction){
    // we just need to add head and remove tail
    // remove one coordinate from the end of vector
    snake_tail = body[body.size() - 1];
    body.pop_back();
    pair < int , int > old_head = body[0]; 
    pair < int , int > new_head = old_head;
    if(direction == UP){
       new_head.first --;
    } else if (direction == DOWN){
       new_head.first ++;
    } if(direction == LEFT){
       new_head.second --;
    } else if (direction == RIGHT){
       new_head.second++;
    }
    body.insert(body.begin(), new_head);
    return body[0];

}


void grow_snake(){
    // add at the last postion -> grow the snake from tail
    // just don't remove the tail
    // ######
    body.push_back(snake_tail);
}

bool has_collision(){
    // collision with border
    // 4 loops ? 
    // what represents my top border ? -> x coordinate = 0
    // what represents my bottom border ? -> x coordinate = LINES - 1
    // what represents my left border ? -> y coordinate = 0
    // what represents my right border ? -> y coordinate = COLS - 1
    pair < int , int > head = body[0];
    int x = head.first;
    int y = head.second;
    if(x == 0 || x == LINES - 1 || y == 0 || y == COLS - 1){
        return true;
    }
    
    // collision with itself

    for(int i = 1;i < body.size();i++){
        if(head == body[i]){
            return true;
        }
    }

    return false;
}

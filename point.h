/*****************************************
 * POINT
 * A very simple point class. Contains the
 * x and y coordinates for a pos as well as
 * the max x and y positions for a game.
 ****************************************/
#ifndef _POINT_H
#define _POINT_H

/*******************
 * POINT
 *******************/
class Point
{
public:
   // constructors
   Point()                : x(0.0 ),  y(0.0 ) {};
   Point(const Point &pt) : x(pt.x),  y(pt.y) {};
   Point(const Point &pt, const float x, const float y) : x(pt.x + x), y(pt.y + y) { };
   Point(bool noError)    : x(0.0 ),  y(0.0 ) {};
   Point(float x, float y): x(x   ),  y(y  )  {};
      
   // getters
   float getX()    const { return x;     };
   float getY()    const { return y;     };
   float getXMax() const { return  800;  };
   float getYMax() const { return  400;  };
   float getXMin() const { return -800;  };
   float getYMin() const { return -400;  };

   float getXMaxBounds() const { return  810;  };
   float getYMaxBounds() const { return  410;  };
   float getXMinBounds() const { return -810;  };
   float getYMinBounds() const { return -410;  };
   

   // setters
   void setX(float x)    { this->x = x;   };
   void setY(float y)    { this->y = y;   };
   void addX(float dx)   { this->x += dx; };
   void addY(float dy)   { this->y += dy; };

private:
   float x;
   float y;
};

#endif 

#ifndef BALL
#define BALL

// A ball.  A ball has a radius, a color, and bounces up and down between
// a maximum height and the xz plane.  Therefore its x and z coordinates
// are fixed.  It uses a lame bouncing algorithm, simply moving up or
// down by 0.05 units at each frame.
class Ball {
private:
    double radius;
    GLfloat* color;
    double maximumHeight;
    Point p;
    double velocity;
    double acc;
    double dt;
public:
    Ball(double r, GLfloat* c, double y, double x, double z): radius(r), color(c) {
        acc = -1.0;
        dt = 0.05;
        p.x = x;
        p.y = y;
        p.z = z;
    }

    double get_radius() { return radius; }
    Point get_point() { return p; }

    bool touching(Ball ball) {
        double x_diff = ball.get_point().x;
        double y_diff = ball.get_point().y;
        double z_diff = ball.get_point().y;
        double h = sqrt(x_diff*x_diff+y_diff*y_diff+z_diff*z_diff);
        if (h <= radius + ball.get_radius()) {
            return true;
        } else {
            return false;
        }
    }
    void update(Ball ball) {
        //    for(std::Ball :: iterator ball = balls.begin(); ball != balls.end(); ++ball) {
        //        if (*it.get_point().getX)
        if (touching(ball))
            acc = -0.5;
        velocity += acc * dt;
        p.y += velocity * dt;
        if (p.y - radius < 0) {
            p.y = radius;
            velocity *= -.8;
        }
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        glTranslated(p.x, p.y, p.z);
        glutSolidSphere(radius, 30, 30);
        glPopMatrix();
        //    }
    }
};

#endif // BALL
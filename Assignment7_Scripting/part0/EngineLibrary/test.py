# Run with:
#
# (Linux & Mac) python3.5 test.py -m ./mygameengine.so
# (Windows) python3.6 test.py -m ./mygameengine.pyd
#
# The program should also run with 'python2.7' but you will have
# to change the 3.5's to 2.7's in your respective build script as
# well as make sure you compiled with 3.5 or 2.7 load flags.
#
# You will see `python3.5-config --includes` for example which corresponds
# to which version of python you are building.
# (In fact, run `python3.5-config --includes` in the terminal to see what it does!)
import mygameengine
from enum import Enum

# Now use some python libraries for random numbers!
import random

BALL_WIDTH = 15
BALL_HEIGHT = 15
BALL_SPEED = 20

PADDLE_WIDTH = 20
PADDLE_HEIGHT = 280
PADDLE_SPEED = 25

WINDOW_WIDTH = 1280
WINDOW_HEIGHT = 720


class Ball:

    def __init__(self, position, velocity):
        self.rect = Vec2()
        self.position = position
        self.velocity = velocity
        # test.DrawRectangle(int(position.x), int(position.y), int(BALL_WIDTH), int(BALL_HEIGHT),230,230,230,0);

    def Update(self, dt):
        self.position += self.velocity * dt

    def Draw(self):
        self.rect.x = int(self.position.x)
        self.rect.y = int(self.position.y)
        test.DrawRectangle(self.rect.x, self.rect.y, BALL_WIDTH, BALL_HEIGHT, 230, 230, 230, 0);

    def collide_with_paddle(self, contact):
        self.position.x += contact.penetration
        self.velocity.x = -self.velocity.x

        if contact.type == CollisionType.Top:
            self.velocity.y = -0.75 * BALL_SPEED
        elif contact.type == CollisionType.Bottom:
            self.velocity.y = 0.75 * BALL_SPEED

    def collide_with_wall(self, contact):
        if contact.type in [CollisionType.Top, CollisionType.Bottom]:
            self.position.y += contact.penetration
            self.velocity.y = -self.velocity.y
        elif contact.type == CollisionType.Left:
            self.position = Vec2(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0)
            self.velocity = Vec2(BALL_SPEED, 0.75 * BALL_SPEED)
        elif contact.type == CollisionType.Right:
            self.position = Vec2(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0)
            self.velocity = Vec2(-BALL_SPEED, 0.75 * BALL_SPEED)


class Paddle:
    def __init__(self, position, velocity):
        self.position = position
        self.velocity = velocity
        self.rect = Vec2()
        self.rect.x = int(self.position.x)
        # test.DrawRectangle(int(position.x), int(position.y), int(PADDLE_WIDTH), int(PADDLE_HEIGHT),125,125,125,2)

    def Update(self, dt):
        self.position.y += self.velocity.y * dt
        if self.position.y < 0:
            self.position.y = 0
        elif self.position.y > WINDOW_HEIGHT - PADDLE_HEIGHT:
            self.position.y = WINDOW_HEIGHT - PADDLE_HEIGHT

    def Draw(self):
        self.rect.y = int(self.position.y)
        test.DrawRectangle(int(self.rect.x), int(self.rect.y), PADDLE_WIDTH, PADDLE_HEIGHT, 230, 230, 230, 2)


class Vec2:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vec2(self.x + other.x, self.y + other.y)

    def __iadd__(self, other):
        self.x += other.x
        self.y += other.y
        return self

    def __mul__(self, scalar):
        return Vec2(self.x * scalar, self.y * scalar)


class CollisionType(Enum):
    None_ = 0
    Top = 1
    Middle = 2
    Bottom = 3
    Left = 4
    Right = 5


class Contact:
    def __init__(self):
        self.type = CollisionType.None_
        self.penetration=0


def check_paddle_collision(ball, paddle):
    ball_left = ball.position.x
    ball_right = ball.position.x + BALL_WIDTH
    ball_top = ball.position.y
    ball_bottom = ball.position.y + BALL_HEIGHT

    paddle_left = paddle.position.x
    paddle_right = paddle.position.x + PADDLE_WIDTH
    paddle_top = paddle.position.y
    paddle_bottom = paddle.position.y + PADDLE_HEIGHT

    contact = Contact()
    if ball_left >= paddle_right:
        return contact

    if ball_right <= paddle_left:
        return contact

    if ball_top >= paddle_bottom:
        return contact

    if ball_bottom <= paddle_top:
        return contact

    paddle_range_upper = paddle_bottom - (2.0 * PADDLE_HEIGHT / 3.0)
    paddle_range_middle = paddle_bottom - (PADDLE_HEIGHT / 3.0)

    if ball.velocity.x < 0:
        contact.penetration = paddle_right - ball_left
    elif ball.velocity.x > 0:
        contact.penetration = paddle_left - ball_right

    if ball_bottom > paddle_top and ball_bottom < paddle_range_upper:
        contact.type = CollisionType.Top
    elif ball_bottom > paddle_range_upper and ball_bottom < paddle_range_middle:
        contact.type = CollisionType.Middle
    else:
        contact.type = CollisionType.Bottom
    return contact


def check_wall_collision(ball):
    ball_left = ball.position.x
    ball_right = ball.position.x + BALL_WIDTH
    ball_top = ball.position.y
    ball_bottom = ball.position.y + BALL_HEIGHT

    contact = Contact()

    if ball_left < 0.0:
        contact.type = CollisionType.Left
    elif ball_right > WINDOW_WIDTH:
        contact.type = CollisionType.Right
    elif ball_top < 0.0:
        contact.type = CollisionType.Top
        contact.penetration = -ball_top
    elif ball_bottom > WINDOW_HEIGHT:
        contact.type = CollisionType.Bottom
        contact.penetration = WINDOW_HEIGHT - ball_bottom

    return contact


# Initialize SDL
test = mygameengine.SDLGraphicsProgram(1280, 720)

# Our main game loop
# Note: This is a simple game that loops for 20 iterations and then
#       exits. 
print("Setting up game loop")
# test.loop();
# for i in range(0,120):

# create ball
ball = Ball(
    Vec2(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0),
    Vec2(BALL_SPEED, 0.0))
# create paddle
paddleOne = Paddle(
    Vec2(50.0, (WINDOW_HEIGHT / 2.0) - (PADDLE_HEIGHT / 2.0)),
    Vec2(0.0, 0.0))

paddleTwo = Paddle(
    Vec2(WINDOW_WIDTH - 50.0, (WINDOW_HEIGHT / 2.0) - (PADDLE_HEIGHT / 2.0)),
    Vec2(0.0, 0.0))

while (test.isRunning()):
    dt = 1

    # Draw the net
    for y in range(WINDOW_HEIGHT):
        if y % 5:
            test.DrawRectangle(WINDOW_WIDTH //2 , y, 1, 1, 255, 255, 255, 1)
    test.Input();
    if test.isKeyDown():
        if test.isWKeyDown():
            paddleOne.velocity.y = -PADDLE_SPEED
        elif test.isSKeyDown():
            paddleOne.velocity.y = PADDLE_SPEED
    else:
        paddleOne.velocity.y = 0

    if test.isKeyDown():
        if test.isUpArrowKeyDown():
            paddleTwo.velocity.y = -PADDLE_SPEED
        elif test.isDownArrowKeyDown():
            paddleTwo.velocity.y = PADDLE_SPEED
    else:
        paddleTwo.velocity.y = 0

    # collision
    contact = check_paddle_collision(ball, paddleOne)
    if contact.type != CollisionType.None_:
        ball.collide_with_paddle(contact)
    else:
        contact = check_paddle_collision(ball, paddleTwo)
        if contact.type != CollisionType.None_:
            ball.collide_with_paddle(contact)
        else:
            contact = check_wall_collision(ball)
            if contact.type != CollisionType.None_:
                ball.collide_with_wall(contact)
                if contact.type == CollisionType.Left:
                    print("player Two WIN!")
                    # playerTwoScore += 1
                    # playerTwoScoreText.set_score(playerTwoScore)
                elif contact.type == CollisionType.Right:
                    print("player One WIN!")
    #                 playerOneScore += 1
    #                 playerOneScoreText.set_score(playerOneScore)
    # e += 1
        # playerOneScoreText.set_score(playerOneScore)
            # if contact.type == CollisionType.Left:
            #     playerTwoScore += 1
            #     playerTwoScoreText.SetScore(playerTwoScore)
            # elif contact.type == CollisionType.Right:
            #     playerOneScore += 1
            #     playerOneScoreText.SetScore(playerOneScore)
    paddleOne.Update(dt)
    paddleTwo.Update(dt)

    # Update the ball position
    ball.Update(dt);

    ball.Draw()
    paddleOne.Draw()
    paddleTwo.Draw()

    # Add a little delay
    test.delay(30);
    # Refresh the screen
    test.flip();
    test.clear();

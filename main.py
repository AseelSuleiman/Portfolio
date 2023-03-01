# Final Project
# CS 111, Reckinger
# Aseel Suleiman
# Fall 2022
# This program is designed as a virtual tour of the Chicago Art Institute
# The user is presented with the outside, start the tour by clicking on the door
# They are then presented with facts about the history of the Art Institute
# They can test their knowledge by choosing an image and taking a quiz on the painting
# Run the code using the top key carrot "Run", next to help, to get interaction in the terminal
# Link for project demo: https://youtu.be/J8t5JBWM5uY


import turtle
import random
import time


# The parameter of this function is first_filename which is defined in main
# This function takes in a background gif, and creates it as the background of the first screen
def first_background(first_filename):
 screen = turtle.Screen()
 screen.update()
 s.bgpic(first_filename)
 pass


# This function has the parameters x, y to direct where the art institute will be drawn
# The building, sides, stairs and door are drawn in this function with turtle graphics
def first_building(x, y):
 t.pensize(5)
 t.pencolor("tan")
 t.speed(5)
 t.penup()
 t.goto(x, y)
 t.pendown()
 t.fillcolor("wheat")
 t.begin_fill() 
 t.forward(600)
 t.left(90)
 t.forward(300)
 t.left(90)
 t.forward(600)
 t.left(90)
 t.forward(300)
 t.end_fill()
 t.penup()
 t.goto(-300,100)
 t.pendown()
 t.begin_fill()
 t.left(90)
 t.forward(600)
 t.left(145)
 t.forward(360)
 t.left(69)
 t.forward(370)
 t.end_fill()
 t.penup()
 t.goto(-300,-200)
 t.pendown()
 t.begin_fill()
 t.right(34)
 t.forward(200)
 t.right(90)
 t.forward(240)
 t.right(90)
 t.forward(200)
 t.right(90)
 t.forward(240)
 t.end_fill()
 t.penup()
 t.goto(300,-200)
 t.pendown()
 t.begin_fill()
 t.left(90)
 t.forward(200)
 t.left(90)
 t.forward(240)
 t.left(90)
 t.forward(200)
 t.left(90)
 t.forward(240)
 t.end_fill()
 t.penup()
 t.goto(-300,-200)
 t.pendown()
 t.begin_fill()
 t.forward(40)
 t.left(90)
 t.forward(600)
 t.left(90)
 t.forward(40)
 t.left(90)
 t.forward(600)
 t.end_fill()
 t.penup()
 t.goto(-300,-240)
 t.pendown()
 t.begin_fill()
 t.forward(40)
 t.left(90)
 t.forward(40)
 t.left(90)
 t.forward(680)
 t.left(90)
 t.forward(40)
 t.left(90)
 t.forward(680)
 t.end_fill()
 t.fillcolor("palegoldenrod")
 t.penup()
 t.goto(-100,-200)
 t.pendown()
 t.begin_fill()
 t.right(90)
 t.forward(200)
 t.right(90)
 t.forward(100)
 t.right(90)
 t.forward(200)
 t.right(90)
 t.forward(100)
 t.penup()
 t.goto(0,-200)
 t.pendown()
 t.right(90)
 t.forward(200)
 t.right(90)
 t.forward(100)
 t.right(90)
 t.forward(200)
 t.right(90)
 t.forward(100)
 t.end_fill()
 t.fillcolor("snow")
 t.penup()
 t.goto(-20, -90)
 t.pendown()
 t.begin_fill()
 t.circle(5,360)
 t.end_fill()
 t.penup()
 t.goto(20, -90)
 t.pendown()
 t.begin_fill()
 t.circle(5,360)
 t.end_fill()
 t.penup()
 t.hideturtle()
 s.tracer(2)
 pass


# The parameters of this function are x1, and y1 which are the coordinates for each pillar
# This function uses turtle graphics to draw out a pillar for the building each time it is called
def pillar(x1,y1):
 t.pensize(1)
 t.pencolor("gray")
 t.speed(5)
 t.penup()
 t.goto(x1,y1)
 t.pendown()
 for i in range(3):
   t.right(90)
   t.forward(300)
   t.left(90)
   t.forward(5)
   t.left(90)
   t.forward(300)
   t.right(90)
   t.forward(3)
 t.fillcolor("gray")
 t.begin_fill()
 t.forward(3)
 t.right(90)
 t.forward(8)
 t.right(90)
 t.forward(32)
 t.right(90)
 t.forward(8)
 t.right(90)
 t.forward(32)
 t.end_fill()
 t.penup()


# This parameters of this function are x, y directing where the bushes will be drawn
# This function uses turtle graphics to draw two bushes on each side of the building
def bushes(x, y):
 t.pencolor("darkgreen")
 t.speed(5)
 t.penup()
 t.goto(x, y)
 t.pendown()
 t.fillcolor("green")
 t.begin_fill()
 t.right(90)
 t.circle(20,180)
 t.right(90)
 t.circle(20,180)
 t.forward(125)
 t.circle(20,180)
 t.right(90)
 t.circle(20,180)
 t.right(180)
 t.circle(20,180)
 t.end_fill()
 t.penup()
 t.goto(-410, -195)
 t.pendown()
 t.begin_fill()
 t.left(180)
 t.circle(20,180)
 t.right(90)
 t.circle(20,180)
 t.forward(125)
 t.circle(20,180)
 t.right(90)
 t.circle(20,180)
 t.right(180)
 t.circle(20,180)
 t.end_fill()
 t.hideturtle()
 t.penup()
 t.goto(300, -170)
 t.pendown()
 t.begin_fill()
 t.left(180)
 t.circle(20,180)
 t.right(90)
 t.circle(20,180)
 t.forward(125)
 t.circle(20,180)
 t.right(90)
 t.circle(20,180)
 t.right(180)
 t.circle(20,180)
 t.end_fill()
 t.penup()
 t.goto(350, -195)
 t.pendown()
 t.begin_fill()
 t.left(180)
 t.circle(20,180)
 t.right(90)
 t.circle(20,180)
 t.forward(125)
 t.circle(20,180)
 t.right(90)
 t.circle(20,180)
 t.right(180)
 t.circle(20,180)
 t.end_fill()
 t.hideturtle()
 pass




text = turtle.Turtle()


# This function has the parameters x, y to direct the text shape to the top of the screen
# This function prints a welcome message along with instructions for the user to continue
def first_text(x, y):
 text.penup()
 text.hideturtle()
 text.goto(x, y)
 text.showturtle()
 text.write("Welcome to the Virtual Chicago Art Institute! Click on the door to come in.", False, align='center', font=('DejaVu Sans Mono', 8, "bold"))
 text.hideturtle()
 pass


# This function has the parameters x, y to direct the starting location of the birds shape
# Birds are added as a turtle shape and move across the screen to appear flying
def first_birds(x, y):
 s.tracer(n=1, delay=5)
 birds = turtle.Turtle()
 birds.hideturtle()
 birds.speed("slowest")
 turtle.addshape("manybirds.gif")
 birds.shape("manybirds.gif")
 birds.penup()
 birds.hideturtle()
 birds.goto(x, y)
 birds.showturtle()
 birds.goto(-600, 200)
 birds.hideturtle()
 # This function has the parameters x, y to only allow users to move to the next screen
# if they click between the x and y coordinates that are within the door frame
# This function is called in the onclick() function only when the user clicks on the door
def erase(x,y):
 if x >= - 100 and x <= 100:
   if y >= -200 and y <= 0:
     s.clear()
     second_screen(x, y)
     turtle.bye()
 pass


# This function has the parameters x1 and x2 to set a range of random x coordinates
# The parameters are also y1 and y2 to set a range of random y coordinates using the random import
# This function adds the paint shape and stamps 20 paint shapes on the screen at random coordinates
def paint(x1, x2, y1, y2):
 paint = turtle.Turtle()
 paint.hideturtle()
 turtle.addshape("paint.gif")
 paint.shape("paint.gif")
 for i in range(0, 20, 1):
   paint.speed("fastest")
   paint.penup()
   paint.hideturtle()
   paint.goto((random.randint(x1, x2)), (random.randint(y1, y2)))
   paint.showturtle()
   paint.stamp()
 pass


# This function takes in x, y coordinates as parameters to add text and images of paintings
# This function also reads in a file, creating a list of the lines to add to the screen
# The facts presented on the second screen come from the two links provided below
# https://theculturetrip.com/north-america/usa/illinois/articles/the-6-most-famous-artworks-at-the-art-institute-of-chicago/
# https://www.artic.edu/about-us/history
# This function interacts with the user in the terminal, allowing them to take a quiz on images 1-3, with the option to leave the tour
def second_screen(x, y):
 s.bgpic("inside.gif")
 text.color("black")
 file = open("History.txt")
 list = []
 for line in file:
   list.append(line)
   text.penup()
   text.hideturtle()
   text.goto(0, -150)
   text.showturtle()
   text.write(line, False, align = "center", font=('DejaVu Sans Mono', 8, "bold"))
   time.sleep(4)
   text.clear()
 text.penup()
 text.goto(-275, 250)
 text.pendown()
 s.clearscreen()
 s.bgcolor("antiquewhite")
 paint(-500, 500, -500, 500)
 text.write("IMAGE 1", False, align='center', font=('DejaVu Sans Mono', 14, "bold"))
 text.penup()
 t.goto(-275,0)
 t.pendown()
 s.addshape('first.gif')
 t.shape('first.gif')
 t.stamp()
 t.penup()
 text.goto(0, 250)
 text.pendown()
 text.write("IMAGE 2", False, align='center', font=('DejaVu Sans Mono', 14, "bold"))
 text.penup()
 t.goto(0,0)
 t.pendown()
 s.addshape('second.gif')
 t.shape('second.gif')
 t.stamp()
 t.penup()
 text.goto(275, 250)
 text.pendown()
 text.write("IMAGE 3", False, align='center', font=('DejaVu Sans Mono', 14, "bold"))
 text.penup()
 t.goto(275, 0)
 t.pendown()
 s.addshape('third.gif')
 t.shape('third.gif')
 t.stamp()
 t.penup()
 points = 0
 answer = "y"
 choose_image = int(input("Enter a number 1-3, Enter 0 to exit: "))
 while choose_image !=0:
   if choose_image == 1:
     print("Time for the quiz on Image 1")
     Q1 = input("Who is the artist of image 1? ")           
     if Q1 == "Georges Seurat":
       print("Correct +1 point")
       points += 1
     else:
       print("Incorrect, answer: Georges Seurat")
     Q2 = input("What is the name of the painting? ")
     if Q2 == "A Sunday Afternoon on the Island of La Grande Jatte":
       print("Correct +1 point")
       points += 1
     else:
       print("Incorrect, answer: A Sunday Afternoon on the Island of La Grande Jatte")
     Q3 = input("When was this painted? ")
     if Q3 == "1884" or Q3 == "1885" or Q3 == "1886":
       print("Correct +1 point")
       points += 1
     else:
       print("Incorrect, it was painted from 1884-1886")
     print("Score = {}".format(points))
  
   if choose_image == 2:
     print("Time for the quiz on Image 2")
     Q1 = input("Who is the artist of image 2? ")
     if Q1 == "Edward Hopper":
       print("Correct +1 point")
       points += 1
     else:
       print("Incorrect, answer: Edward Hopper")
     Q2 = input("What is the name of the painting? ")
     if Q2 == "Nighthawks":
       print("Correct +1 point")
       points += 1
     else:
       print("Incorrect, answer: Nighthawks")
     Q3 = input("When was this painted? ")
     if Q3 == "1942":
       print("Correct +1 point")
       points += 1
     else:
       print("Incorrect, it was painted in 1942")
     print("Score = {}".format(points))
  
   if choose_image == 3:
     print("Time for the quiz on Image 3")
     Q1 = input("Who is the artist of image 3? ")
     if Q1 == "Grant Wood":
       print("Correct +1 point")
       points += 1
     else:
       print("Incorrect, answer: Grant Wood")
     Q2 = input("What is the name of the painting? ")
     if Q2 == "American Gothic":
       print("Correct +1 point")
       points += 1
     else:
       print("Incorrect, answer: American Gothic")
     Q3 = input("When was this painted? ")
     if Q3 == "1930":
       print("Correct +1 point")
       points += 1
     else:
       print("Incorrect, it was painted in 1930")
     print("Score = {}".format(points))
   choose_image = int(input("Enter a number 1-3, Enter 0 to exit: "))


# This is the main code, it calls for all the created functions
# It also listens for the click of the user on the first screen to call on the erase function
if __name__ == "__main__":
 s = turtle.getscreen()
 t = turtle.Turtle()
 first_filename = "newback.gif"
 first_background(first_filename)
 first_building(-300, -200)
 first_birds(600, 200)
 pillar(-130,-200)
 pillar(-200,-200)
 pillar(146,-200)
 pillar(216,-200)
 bushes(-330, -170)
 first_text(0, 150)
 s.onclick(erase)
 s.listen()
 turtle.mainloop()

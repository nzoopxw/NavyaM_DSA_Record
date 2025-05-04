// menu-driven program that calculates and displays the area of a square, cube, rectangle, and cuboid

#include<stdio.h>

void Index(){
    printf("1.Square\n");
    printf("2.Rectangle\n");
    printf("3.Cube\n");
    printf("4.Cuboid\n");
    printf("5.Exit\n\n");
}

class AreaAndVolume{
private:
    int squareSide;        
    int rectangleLength;    
    int rectangleBreadth;  
    int cuboidLength;       
    int cuboidBreadth;     
    int cuboidHeight;      

public:
// function to calculate Square's area
    void calculateSquareArea(){
        printf("Enter the side length of the square: ");
        scanf("%d", &squareSide);
        
        printf("Area of the square is: %d sq.cm\n", squareSide * squareSide);
    }
// function to calculate Rectangle's area
    void calculateRectangleArea(){
        printf("Enter the length of the rectangle: ");
        scanf("%d", &rectangleLength);
        printf("Enter the breadth of the rectangle: ");
        scanf("%d", &rectangleBreadth);
        printf("Area of the rectangle is: %d sq.cm\n", rectangleLength * rectangleBreadth);
    }
// function to calculate Cube's volume
    void calculateCubeVolume(){
        printf("Enter the side length of the cube: ");
        scanf("%d", &squareSide); 
        
        printf("Volume of the cube is: %d cubic cm\n", squareSide * squareSide * squareSide);
    }

// function to calculate Cuboid's volume
    void calculateCuboidVolume(){
        printf("Enter the length of the cuboid: ");
        scanf("%d", &cuboidLength);
        printf("Enter the breadth of the cuboid: ");
        scanf("%d", &cuboidBreadth);
        printf("Enter the height of the cuboid: ");
        scanf("%d", &cuboidHeight);
        printf("Volume of the cuboid is: %d cubic cm\n", cuboidLength * cuboidBreadth * cuboidHeight);
    }
};

int main(){
    int choice;
    AreaAndVolume obj;

    Index();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while(choice != 5){
        switch(choice){
            case 1:
                obj.calculateSquareArea();
                break;

            case 2:
                obj.calculateRectangleArea();
                break;

            case 3:
                obj.calculateCubeVolume();
                break;

            case 4:
                obj.calculateCuboidVolume();
                break;
            default: printf("Enter a valid number \n");

        }

        Index();
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    
    return 0;
}

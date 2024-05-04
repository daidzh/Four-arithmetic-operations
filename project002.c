//#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define NUM_ELEVATORS 4
#define NUM_FLOORS 21

// 电梯结构体
typedef struct {
    int currentFloor;  // 当前楼层
    bool directionUp;  // 电梯运行方向，true表示向上，false表示向下
    bool servingFloors[NUM_FLOORS]; // 电梯服务楼层的数组
} Elevator;

// 初始化电梯
void initializeElevator(Elevator *elevator, int maxFloor) {
    elevator->currentFloor = 0;
    elevator->directionUp = true;
    for (int i = 0; i < NUM_FLOORS; i++) {
        elevator->servingFloors[i] = (i <= maxFloor);
    }
}

// 打印电梯状态
void printElevatorStatus(Elevator *elevator, int elevatorNumber) {
    printf("Elevator %d: Current Floor: %d, Direction: %s\n", elevatorNumber, elevator->currentFloor, elevator->directionUp ? "Up" : "Down");
}

// 主函数
int main() {
    Elevator elevators[NUM_ELEVATORS];
    int userRequests[NUM_FLOORS] = {0}; // 用户请求数组，记录每层楼的请求次数

    // 初始化电梯
    initializeElevator(&elevators[0], 10);
    initializeElevator(&elevators[1], 10);
    initializeElevator(&elevators[2], 10);
    initializeElevator(&elevators[3], 20);

    // 模拟用户请求
    userRequests[5] = 1; // 举例：在第5层有一个用户请求
    // 根据用户请求调度电梯，这里需要根据具体的调度算法进行实现

    // 打印电梯状态
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printElevatorStatus(&elevators[i], i + 1);
    }

    return 0;
}
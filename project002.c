//#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define NUM_ELEVATORS 4
#define NUM_FLOORS 21

// ���ݽṹ��
typedef struct {
    int currentFloor;  // ��ǰ¥��
    bool directionUp;  // �������з���true��ʾ���ϣ�false��ʾ����
    bool servingFloors[NUM_FLOORS]; // ���ݷ���¥�������
} Elevator;

// ��ʼ������
void initializeElevator(Elevator *elevator, int maxFloor) {
    elevator->currentFloor = 0;
    elevator->directionUp = true;
    for (int i = 0; i < NUM_FLOORS; i++) {
        elevator->servingFloors[i] = (i <= maxFloor);
    }
}

// ��ӡ����״̬
void printElevatorStatus(Elevator *elevator, int elevatorNumber) {
    printf("Elevator %d: Current Floor: %d, Direction: %s\n", elevatorNumber, elevator->currentFloor, elevator->directionUp ? "Up" : "Down");
}

// ������
int main() {
    Elevator elevators[NUM_ELEVATORS];
    int userRequests[NUM_FLOORS] = {0}; // �û��������飬��¼ÿ��¥���������

    // ��ʼ������
    initializeElevator(&elevators[0], 10);
    initializeElevator(&elevators[1], 10);
    initializeElevator(&elevators[2], 10);
    initializeElevator(&elevators[3], 20);

    // ģ���û�����
    userRequests[5] = 1; // �������ڵ�5����һ���û�����
    // �����û�������ȵ��ݣ�������Ҫ���ݾ���ĵ����㷨����ʵ��

    // ��ӡ����״̬
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printElevatorStatus(&elevators[i], i + 1);
    }

    return 0;
}
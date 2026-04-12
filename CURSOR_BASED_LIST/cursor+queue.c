// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 30

typedef struct{
    char name[30];
    int speed;
    int acceleration;
    int handling;
    int traction;
    
}Stats;


typedef struct{
    Stats Chassis;
    Stats Wheels;
    Stats Parachute;
    Stats Total;
    
}Car;

typedef struct{
    char name[30];
    char desc[50];
}Item;

typedef struct {
    char name[30];
    int weight;
}Character;


typedef struct{
    char IGN[30];
    int idNum;
}Player;

typedef struct{
    Player player;
    Character character;
    Car car;
    Item inventory[2];
    int inventoryCount;
    int coins;
    
}Data;



typedef struct{
   Data data;
   int next;
    
}Cell , HeapSpace[MAX];


typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;


Stats chassisByChoice(int choice){
    Stats s;
    if (choice == 2) {
        strcpy(s.name, "MediumChassis");
        s.speed = 12;
        s.acceleration = 8;
        s.handling = 9;
        s.traction = 11;
    } else if (choice == 3) {
        strcpy(s.name, "HeavyChassis");
        s.speed = 15;
        s.acceleration = 5;
        s.handling = 6;
        s.traction = 14;
    } else {
        strcpy(s.name, "LightChassis");
        s.speed = 10;
        s.acceleration = 10;
        s.handling = 10;
        s.traction = 10;
    }
    return s;
}

Stats wheelsByChoice(int choice){
    Stats s;
    if (choice == 2) {
        strcpy(s.name, "StandardWheels");
        s.speed = 11;
        s.acceleration = 9;
        s.handling = 10;
        s.traction = 10;
    } else if (choice == 3) {
        strcpy(s.name, "MonsterWheels");
        s.speed = 13;
        s.acceleration = 6;
        s.handling = 7;
        s.traction = 15;
    } else {
        strcpy(s.name, "LightWheels");
        s.speed = 10;
        s.acceleration = 10;
        s.handling = 10;
        s.traction = 10;
    }
    return s;
}

Stats parachuteByChoice(int choice){
    Stats s;
    if (choice == 2) {
        strcpy(s.name, "SuperGlider");
        s.speed = 9;
        s.acceleration = 11;
        s.handling = 10;
        s.traction = 9;
    } else if (choice == 3) {
        strcpy(s.name, "BowserGlider");
        s.speed = 10;
        s.acceleration = 7;
        s.handling = 6;
        s.traction = 12;
    } else {
        strcpy(s.name, "LightParachute");
        s.speed = 10;
        s.acceleration = 10;
        s.handling = 10;
        s.traction = 10;
    }
    return s;
}

void recomputeCarTotal(Car *car){
    strcpy(car->Total.name, "Total");
    car->Total.speed =
        car->Chassis.speed + car->Wheels.speed + car->Parachute.speed;
    car->Total.acceleration =
        car->Chassis.acceleration + car->Wheels.acceleration +
        car->Parachute.acceleration;
    car->Total.handling =
        car->Chassis.handling + car->Wheels.handling + car->Parachute.handling;
    car->Total.traction =
        car->Chassis.traction + car->Wheels.traction + car->Parachute.traction;
}

void applyCarByChoice(Car *car, int chassisChoice, int wheelsChoice, int paraChoice){
    car->Chassis = chassisByChoice(chassisChoice);
    car->Wheels = wheelsByChoice(wheelsChoice);
    car->Parachute = parachuteByChoice(paraChoice);
    recomputeCarTotal(car);
}

Character characterByChoice(int choice){
    Character ch;

    if (choice == 1) {
        strcpy(ch.name, "Toad");
        ch.weight = 10;
    } else if (choice == 2) {
        strcpy(ch.name, "Mario");
        ch.weight = 15;
    } else if (choice == 3) {
        strcpy(ch.name, "Bowser");
        ch.weight = 25;
    } else if (choice == 4) {
        strcpy(ch.name, "Luigi");
        ch.weight = 14;
    } else if (choice == 5) {
        strcpy(ch.name, "Peach");
        ch.weight = 12;
    } else if (choice == 6) {
        strcpy(ch.name, "Yoshi");
        ch.weight = 11;
    } else if (choice == 7) {
        strcpy(ch.name, "DonkeyKong");
        ch.weight = 22;
    } else if (choice == 8) {
        strcpy(ch.name, "Waluigi");
        ch.weight = 13;
    } else if (choice == 9) {
        strcpy(ch.name, "Rosalina");
        ch.weight = 12;
    } else if (choice == 10) {
        strcpy(ch.name, "Wario");
        ch.weight = 18;
    } else {
        strcpy(ch.name, "Toad");
        ch.weight = 10;
    }
    return ch;
}

void printCharacterRoster(){
    int i;
    Character tmp;

    printf("Characters (enter 1-10):\n");
    for (i = 1; i <= 10; i++) {
        tmp = characterByChoice(i);
        printf("  %2d - %-12s  weight %d\n", i, tmp.name, tmp.weight);
    }
}

Item itemByChoice(int choice){
    Item it;

    if (choice == 2) {
        strcpy(it.name, "RedShell");
        strcpy(it.desc, "Shoot a guided red shell in front of you!");
    } else if (choice == 3) {
        strcpy(it.name, "Banana");
        strcpy(it.desc, "Drop a banana peel behind you!");
    } else if (choice == 4) {
        strcpy(it.name, "Mushroom");
        strcpy(it.desc, "Gain a short speed boost!");
    } else if (choice == 5) {
        strcpy(it.name, "FireFlower");
        strcpy(it.desc, "Throw fireballs forward!");
    } else if (choice == 6) {
        strcpy(it.name, "Lightning");
        strcpy(it.desc, "Shock all opponents!");
    } else {
        strcpy(it.name, "GreenShell");
        strcpy(it.desc, "Shoot a green shell in front of you!");
    }
    return it;
}

void printItemRoster(){
    int i;
    Item tmp;

    printf("Items (enter 1-6):\n");
    for (i = 1; i <= 6; i++) {
        tmp = itemByChoice(i);
        printf("  %2d - %s\n", i, tmp.name);
    }
}

void init(VHeap *V){
    V->avail = 0;

    for(int i = 0; i < MAX - 1; i++){
        V->H[i].next = i+1;
        V->H[i].data.inventoryCount = 0;
    }

    V->H[MAX - 1].next = -1;
    V->H[MAX - 1].data.inventoryCount = 0;

}

int allocSpace(VHeap *V){

    if(V->avail != -1){
        int idx = V->avail;
        V->avail = V->H[V->avail].next;
        return idx;
    } else {
        return -1;
    }
}

void deallocSpace(VHeap *V, int idx){
    if (idx < 0 || idx >= MAX)
        return;
    V->H[idx].data.inventoryCount = 0;
    V->H[idx].next = V->avail;
    V->avail = idx;
}

bool removeByID(List *L, VHeap *V, int idNum){
    int prev;
    int curr;

    if (*L == -1)
        return false;

    if (V->H[*L].data.player.idNum == idNum) {
        curr = *L;
        *L = V->H[curr].next;
        deallocSpace(V, curr);
        return true;
    }

    prev = *L;
    curr = V->H[prev].next;
    while (curr != -1) {
        if (V->H[curr].data.player.idNum == idNum) {
            V->H[prev].next = V->H[curr].next;
            deallocSpace(V, curr);
            return true;
        }
        prev = curr;
        curr = V->H[curr].next;
    }
    return false;
}

bool insertLast(int *L, VHeap *V, Cell data){
    int idx = allocSpace(V);

    if (idx == -1) {
        return false;
    }

    V->H[idx] = data;
    V->H[idx].next = -1;

    if (*L == -1) {
        *L = idx;
    } else {
        int trav = *L;
        for (; V->H[trav].next != -1; trav = V->H[trav].next)
            ;
        V->H[trav].next = idx;
    }

    return true;
}

void display(int *L, VHeap *V){
    int trav = *L;
    int count;

    printf("\n");
    printf(" +------+--------+----------------------+----------------------+------+------+------+------+-------+\n");
    printf(" |  #   |   ID   |        IGN           |      Character       | SPD  | ACC  | HND  | TRC  | Coins |\n");
    printf(" +------+--------+----------------------+----------------------+------+------+------+------+-------+\n");

    for (count = 1; trav != -1; trav = V->H[trav].next, count++) {
        printf(" | %4d | %6d | %-20s | %-20s | %4d | %4d | %4d | %4d | %5d |\n",
               count,
               V->H[trav].data.player.idNum,
               V->H[trav].data.player.IGN,
               V->H[trav].data.character.name,
               V->H[trav].data.car.Total.speed,
               V->H[trav].data.car.Total.acceleration,
               V->H[trav].data.car.Total.handling,
               V->H[trav].data.car.Total.traction,
               V->H[trav].data.coins);
    }

    printf(" +------+--------+----------------------+----------------------+------+------+------+------+-------+\n");
    printf("\n");
}

bool isFull(int inventoryCount){
    return inventoryCount >= 2 ? true : false;
}

bool isEmpty(int inventoryCount){
    return inventoryCount == 0 ? true : false;
}

 int findPlayer(List *L, VHeap *V, int idNum){
    for (int trav = *L; trav != -1; trav = V->H[trav].next) {
        if (V->H[trav].data.player.idNum == idNum)
            return trav;
    }
    return -1;
}

bool enq(List *L, VHeap *V, int idNum, Item data){
    int trav = findPlayer(L, V, idNum);
    if (trav == -1) {
        printf("Player not found\n");
        return false;
    }

    if (isFull(V->H[trav].data.inventoryCount)) {
        printf("Inventory is full\n");
        return false;
    }

    V->H[trav].data.inventory[V->H[trav].data.inventoryCount] = data;
    V->H[trav].data.inventoryCount++;
    return true;
}

bool deq(List *L, VHeap *V, int idNum, Item *out){
    Item none = {0};

    int trav = findPlayer(L, V, idNum);
    if (trav == -1) {
        printf("Player not found\n");
         *out = none;
        
        return false;
    }

    if (isEmpty(V->H[trav].data.inventoryCount)) {
        printf("Inventory is empty\n");
        *out = none;
        return false;
    }

    {
        Item removed = V->H[trav].data.inventory[0];
        if (V->H[trav].data.inventoryCount == 2) {
            V->H[trav].data.inventory[0] = V->H[trav].data.inventory[1];
        }
        V->H[trav].data.inventoryCount--;
        if (out)
            *out = removed;
        return true;
    }
}

void displayInventory(List *L, VHeap *V, int idNum){
    int trav = findPlayer(L, V, idNum);
    if (trav == -1) {
        printf("\nPlayer not found\n");
    } else {
        printf("Inventory:\n");
        int n = V->H[trav].data.inventoryCount;
        for (int i = 0; i < n; i++) {
            Item it;
            if (deq(L, V, idNum, &it)) {
                printf("[%d] %s\n", i + 1, it.name);
                enq(L, V, idNum, it);
            }
        }
    }
}


void populate(List *L, VHeap *V){
    Cell cell;

    /* PLAYER 1 LIGHT */
    strcpy(cell.data.player.IGN, "PLAYER67");
    cell.data.player.idNum = 67;
    cell.data.character = characterByChoice(1);
    cell.data.coins = 67;
    applyCarByChoice(&cell.data.car, 1, 1, 1);
    cell.data.inventoryCount = 0;
    insertLast(L, V, cell);
    enq(L, V, 67, itemByChoice(1));
    enq(L, V, 67, itemByChoice(2));

    /* PLAYER 2 MEDIUM */
    strcpy(cell.data.player.IGN, "PLAYER88");
    cell.data.player.idNum = 88;
    cell.data.character = characterByChoice(2);
    cell.data.coins = 120;
    applyCarByChoice(&cell.data.car, 2, 2, 2);
    cell.data.inventoryCount = 0;
    insertLast(L, V, cell);
    enq(L, V, 88, itemByChoice(3));
    enq(L, V, 88, itemByChoice(4));

    /* PLAYER 3 HEAVY */
    strcpy(cell.data.player.IGN, "PLAYER99");
    cell.data.player.idNum = 99;
    cell.data.character = characterByChoice(3);
    cell.data.coins = 200;
    applyCarByChoice(&cell.data.car, 3, 3, 3);
    cell.data.inventoryCount = 0;
    insertLast(L, V, cell);
    enq(L, V, 99, itemByChoice(5));
    enq(L, V, 99, itemByChoice(6));
}

Cell promptNewPlayer(void){
    Cell c = {0};
    int ch, wh, pa, charPick;

    printf("Enter IGN: ");
    scanf("%s", c.data.player.IGN);
    printf("Enter ID number: ");
    scanf("%d", &c.data.player.idNum);
    printCharacterRoster();
    printf("Your pick: ");
    scanf("%d", &charPick);
    c.data.character = characterByChoice(charPick);
    printf("Enter coins: ");
    scanf("%d", &c.data.coins);

    printf("Chassis (1=Light 2=Medium 3=Heavy): ");
    scanf("%d", &ch);
    printf("Wheels (1=Light 2=Medium 3=Heavy): ");
    scanf("%d", &wh);
    printf("Parachute (1=Light 2=Medium 3=Heavy): ");
    scanf("%d", &pa);

    applyCarByChoice(&c.data.car, ch, wh, pa);
    c.data.inventoryCount = 0;

    return c;
}

int main(){
    VHeap V;
    List L = -1;

    init(&V);
    populate(&L, &V);

    int loop = 0;
    while (loop != 7) {
        printf("\n========== Menu ==========\n");
        printf("1 - Insert new player\n");
        printf("2 - Display leaderboard\n");
        printf("3 - Add inventory item\n");
        printf("4 - Remove inventory item\n");
        printf("5 - Display inventory\n");
        printf("6 - Remove player by ID\n");
        printf("7 - Exit\n");
        printf("Choice: ");
        scanf("%d", &loop);

        if (loop == 1) {
            Cell c = promptNewPlayer();
            insertLast(&L, &V, c);
            printf("Player inserted.\n");
        }
        if (loop == 2) {
            display(&L, &V);
        }
        if (loop == 3) {
            int idNum, pick;
            Item toAdd;
            printf("Player ID: ");
            scanf("%d", &idNum);
            printItemRoster();
            printf("Your pick: ");
            scanf("%d", &pick);
            toAdd = itemByChoice(pick);
            if (enq(&L, &V, idNum, toAdd))
                printf("Item added to inventory.\n");
        }
        if (loop == 4) {
            int idNum;
            Item it;
            printf("Player ID: ");
            scanf("%d", &idNum);
            if (deq(&L, &V, idNum, &it))
                printf("Item removed from inventory (%s).\n", it.name);
        }
        if (loop == 5) {
            int idNum;
            printf("Player ID: ");
            scanf("%d", &idNum);
            displayInventory(&L, &V, idNum);
        }
        if (loop == 6) {
            int idNum;
            printf("Player ID to remove: ");
            scanf("%d", &idNum);
            if (removeByID(&L, &V, idNum))
                printf("Player removed.\n");
            else
                printf("Player not found.\n");
        }
        if (loop == 7) {
            printf("Exiting...\n");
        }
    }

    return 0;
}
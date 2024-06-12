#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_CONTAINERS 100


typedef struct {
    int id;
    double weight;
    double volume;
} Item;


typedef struct {
    int id;
    double totalWeight;
    double totalVolume;
    Item items[MAX_ITEMS];
    int itemCount;
} Container;


void initializeContainer(Container *container, int id) {
    container->id = id;
    container->totalWeight = 0.0;
    container->totalVolume = 0.0;
    container->itemCount = 0;
}


void addItemToContainer(Container *container, Item item) {
    container->items[container->itemCount] = item;
    container->totalWeight += item.weight;
    container->totalVolume += item.volume;
    container->itemCount++;
}


void displayContainer(Container container) {
    printf("Container %d:\n", container.id);
    printf("Total Weight: %.2f, Total Volume: %.2f\n", container.totalWeight, container.totalVolume);
    printf("Items:\n");
    for (int i = 0; i < container.itemCount; i++) {
        printf("Item %d - Weight: %.2f, Volume: %.2f\n", container.items[i].id, container.items[i].weight, container.items[i].volume);
    }
    printf("\n");
}


void packItems(Item items[], int numItems, int numContainers, double maxWeight, double maxVolume) {
    Container containers[MAX_CONTAINERS];
    int containerIndex = 0;

 
    for (int i = 0; i < numContainers; i++) {
        initializeContainer(&containers[i], i + 1);
    }


    for (int i = 0; i < numItems; i++) {
        if (containerIndex >= numContainers) {
            printf("Insufficient containers to pack all items.\n");
            break;
        }

        if (containers[containerIndex].totalWeight + items[i].weight <= maxWeight &&
            containers[containerIndex].totalVolume + items[i].volume <= maxVolume) {
            addItemToContainer(&containers[containerIndex], items[i]);
        } else {
            containerIndex++;
            i--; 
        }
    }

   
    for (int i = 0; i <= containerIndex; i++) {
        displayContainer(containers[i]);
    }
}

int main() {
    int numItems, numContainers;
    double maxWeight, maxVolume;
    Item items[MAX_ITEMS];

   
    printf("Enter number of items: ");
    scanf("%d", &numItems);

    printf("Enter number of containers: ");
    scanf("%d", &numContainers);


    printf("Enter maximum weight for each container: ");
    scanf("%lf", &maxWeight);

    printf("Enter maximum volume for each container: ");
    scanf("%lf", &maxVolume);

  
    for (int i = 0; i < numItems; i++) {
        printf("Enter weight and volume for item %d: ", i + 1);
        scanf("%lf %lf", &items[i].weight, &items[i].volume);
        items[i].id = i + 1;
    }

 
    packItems(items, numItems, numContainers, maxWeight, maxVolume);

    return 0;
}

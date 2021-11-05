#include"polygon.h"

void fillVertexList(Vertex* vertexList, char* rest, char* temp)
{
	int i = 0;
	int x = 0;
	int y = 0;
	while(i != 2)
	{ //repeat to add to vertex x and y coord
		i = sscanf(rest, "%d %d %[^\n]\n", &x, &y, rest);
		vertexList->x = x;
		vertexList->y = y;
		vertexList++;
	}
}

int main(int argc, char *argv[]){
    char firsttoken[20];
    char rest[100];
    char *token [3];
    int polygonindex;
	char input_buf[64];
    char data[64];
	int polygonIndex = 0;
	

	if(argc == 2){
		int num = atoi(argv[1]);
		Polygon** polygonList;
		printf("\nNumber: %d\n" , num);

		while(strcmp(input_buf, "quit") != 0){
			printf("\nEnter something: ");
			fgets(input_buf,64,stdin);
			
			sscanf(input_buf, "%s %[^\n]\n", firsttoken, rest);

			if(strcmp(firsttoken, "quit") == 0){
				return 0;
			}
			if(strcmp(firsttoken, "add") == 0){
				
				if (polygonIndex < num)
				{
					int n = strlen(rest), x, y, i = 0, numOfVerticies = 0;
					char temp[100];

					rest[n] = '\n'; //add new line to rest
					rest[n+1] = '0'; //add 0 at the end to know when to stop
					strcpy(temp, rest); //copy THIS rest to temp

					while(i != 2){ //find the number of verticies
						i = sscanf(rest, "%d %d %[^\n]\n", &x, &y, rest);
						numOfVerticies++; //count var
						
					}

					Polygon* p = malloc(sizeof(Polygon));
					p->numberOfVertices = numOfVerticies;
					p->shiftDirection = NONE;
					p->vertexList = (Vertex*)malloc( p->numberOfVertices * sizeof(Vertex));

					i = numOfVerticies = 0;
					strcpy(rest, temp);

					fillVertexList(p->vertexList, rest, temp);
					printf("\n=========================\n");
					printf("Polygon Added.");
					printf("\n=========================\n");
					
					polygonList[polygonIndex] = p;
					polygonIndex++;
				}
				else
				{
					printf("\nMAX AMOUNT OF POLYGONS\n");
				}
				
				
			}
			if(strcmp(firsttoken, "summary") == 0){
				for(int k = 0; k < polygonIndex; k++){
					printf("\n=========================");
					double xAvg, yAvg, num = 0;
					double sumX = 0;
					double sumY = 0;
					
					for(int l = 0; l < polygonList[k]->numberOfVertices; l++){ //you need the number of vertices of numbers ie 2 for 2xs and 2ys
						sumX += (double)polygonList[k]->vertexList[l].x;
						sumY += (double)polygonList[k]->vertexList[l].y;
						

					}
					printf("\nPolygon #%d has %d. It's centroid is at (%.1f, %.1f) " , k, polygonList[k]->numberOfVertices, sumX/(double)polygonList[k]->numberOfVertices,sumY/(double)polygonList[k]->numberOfVertices);
					printf("\n=========================");
				}
				
			}

		}
	}
	else{
		printf("\nNot enough arguments! \n");
		return 0;
	}
		
	return 0;
}


struct song parseSong(char *songPath){
    struct song parsing;
    char mode[30];
    FILE *file = fopen(songPath, "r");
    char line[128];
    while (fgets(line, sizeof(line), file) != NULL) {
        // printf("File content: %s\n", line);
        if(line[0]=='['){
            // index++;
            // indexs=line[0];
            if(line[1] == 'M'){
                strcpy(mode,"Meta");
            }else if(line[1] == 'G'){
                strcpy(mode,"Gen");
            }else{
                strcpy(mode,"UNDEFINED!!!");
            }
        }else{
            if (strcmp(mode,"Gen")==0){
                char* split=strtok(line,":");
                char statew[20];
                strcpy(statew,"null");
                while(split != NULL)
                {
                    char* word=split;
                    if(strcmp(statew,"null")==0){
                        if(strcmp(word,"AudioFilename")==0){
                            strcpy(statew,"File");
                            // printf(word);
                        }
                    }else{
                        // word[strcspn(word, "\n")]=0;
                        if(strcmp(statew,"File")==0){
                            index+=1;
                            strcpy(parsing.audio,word);
                            // printf(word);
                        }
                        strcpy(statew,"null");
                    }
                    
                    // printf(word);
                    split=strtok(NULL,"\r\n");
                }
             
            }
            if (strcmp(mode,"Meta")==0){
                // index++;
                char* split=strtok(line,":");
                char statew[20];
                strcpy(statew,"null");
                while(split != NULL)
                {
                    char* word=split;
                    if(strcmp(statew,"null")==0){
                        if(strcmp(word,"Title")==0){
                            strcpy(statew,"Title");
                            // printf(word);
                        }
                        if(strcmp(word,"Artist")==0){
                            strcpy(statew,"Artist");
                            // printf(word);
                        }
                        if(strcmp(word,"Creator")==0){
                            strcpy(statew,"Author");
                            // printf(word);
                        }
                    }else{
                        
                        // word[strcspn(word, "\n")]=0;
                        if(strcmp(statew,"Title")==0){
                            index+=1;
                            strcpy(parsing.title,word);
                            // printf(word);
                        }
                        if(strcmp(statew,"Artist")==0){
                            index+=1;
                            strcpy(parsing.artist,word);
                            // printf(word);
                        }
                        if(strcmp(statew,"Author")==0){
                            index+=1;
                            strcpy(parsing.author,word);
                            // printf(word);
                        }
                        strcpy(statew,"null");
                    }
                    // printf(word);
                    split=strtok(NULL,"\r\n");
                }
            }
        }

    }
                            //printf(songs);
    sprintf(indexs, "%d", index);
    return (parsing);
}


void printSong(struct song s){
    printf("\n --- \n\n");
    
    char temp[50];
    strcpy(temp, "Title : ");
    strcat(temp,s.title);
    printf(temp);

    strcpy(temp, "Artist : ");
    strcat(temp,s.artist);
    printf(temp);
    
    strcpy(temp, "Charted By : ");
    strcat(temp,s.author);
    printf(temp);

}
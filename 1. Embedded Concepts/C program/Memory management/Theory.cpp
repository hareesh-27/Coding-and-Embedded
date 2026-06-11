Memory is divided into many sections.
Here we will be seeing about
  - Text
  - Data  -> Further divided into initialised data segment and uninitialised data segment
  - Stack
  - Heap

  Text :
        Test segment stores the executable code of the program like functions, instns.

  Data :
        Data segment stores global and static variables present in the program
        Data segment is divided into 2 parts - initialised and uninitialised data segments.

        Initialised data segment :
                                  As the name suggests it stores initialised global and static variables

                                  // Global variables (stored in initialized data segment)
                                  int globalVar = 10;
                                  char message[] = "Hello";

                                  int main()
                                  {
                                      // Static variable (also stored in initialized data segment)
                                      static int staticVar = 20;
                                  
                                      printf("Global variable: %d\n", globalVar);
                                      printf("Static variable: %d\n", staticVar);
                                      printf("Message: %s\n", message);
                                  
                                      return 0;
                                  }

       Uninitialised data segment : 
                                  As the name suggests it stores uninitialised global and static variables
                                  These variables are automatically assigned to 0 at runtime.

                                  // Global uninitialized variables (stored in BSS segment)
                                  int globalVar;
                                  char message[50];
                                  
                                  int main()
                                  {
                                      // Static uninitialized variable (also stored in BSS)
                                      static int staticVar;
                                  
                                      // Assigning values at runtime
                                      globalVar = 10;
                                      staticVar = 20;
                                      snprintf(message, sizeof(message), "Hello BSS");
                                  
                                      printf("Global variable: %d\n", globalVar);
                                      printf("Static variable: %d\n", staticVar);
                                      printf("Message: %s\n", message);
                                  
                                      return 0;
                                  }

      Stack :
              Stack stores local variables, return addresses for each function call.

      Heap :
            Heap segment is used for dynamic memory allocation
            The main players are : 
                                  malloc()   - memory allocation
                                  realloc()  - reallocate
                                  calloc()   - contiguous allocation 

            malloc() : malloc() is used to allocate sinlge block of contiguous memory at heap during runtime.
                       The memory allocated is uninitialised -> means it contains garbage values.


                        int main()
                        {
                            int *ptr = (int *)malloc(sizeof(int) * 5);
                        
                            // Populate the array
                            for (int i = 0; i < 5; i++)
                                ptr[i] = i + 1;
                        
                            // Print the array
                            for (int i = 0; i < 5; i++)
                                printf("%d ", ptr[i]);      // 1 2 3 4 5 
                            return 0;
                        }

            calloc() : Same as malloc() but only difference is the allocated memory is initialised to 0.

                        int main() {
                        int *ptr = (int *)calloc(5, sizeof(int));
                        
                        // Checking if failed or pass
                        if (ptr == NULL) {
                            printf("Allocation Failed");
                            exit(0);
                        }
                        
                        // No need to populate as already
                        // initialized to 0
                            
                        // Print the array
                        for (int i = 0; i < 5; i++)
                            printf("%d ", ptr[i]);      // 0 0 0 0 0
                        return 0;
                    }


            realloc() :  is used to resize a previously allocated memory block

                        int main() {
                        int *ptr = (int *)malloc(5 * sizeof(int));
                    
                        // Resize the memory block to hold 10 integers
                        ptr = (int *)realloc(ptr, 10 * sizeof(int));
                        
                        // Check for allocation failure
                        if (ptr == NULL) {
                            printf("Memory Reallocation Failed");
                            exit(0);
                        }
                    
                        return 0;
                    }







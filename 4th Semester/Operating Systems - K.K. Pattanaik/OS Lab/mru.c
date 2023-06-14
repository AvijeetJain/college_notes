#include <stdio.h>

#define MAX_FRAMES 20 // Maximum number of frames in memory

int main() {
    int reference_string[20], page_faults = 0;
    int frames[MAX_FRAMES], frame_count[MAX_FRAMES], frame_index = 0; // frames array stores the page numbers currently in memory, frame_count array stores the time at which each frame was last used
    int num_pages, num_frames, i, j, k;

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the reference string: ");
    for(i = 0; i < num_pages; i++) {
        scanf("%d", &reference_string[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    // Initialize all frames to -1 (indicating that they are currently empty)
    for(i = 0; i < num_frames; i++) {
        frames[i] = -1;
        frame_count[i] = -1;
    }

    // Iterate over the reference string
    for(i = 0; i < num_pages; i++) {
        int page_number = reference_string[i];
        int page_found = 0;

        // Check if the current page is already in memory
        for(j = 0; j < num_frames; j++) {
            if(frames[j] == page_number) {
                page_found = 1;
                frame_count[j] = i + 1; // Update the time at which this frame was last used to the current iteration
                break;
            }
        }

        // If the page is not in memory, replace the most recently used page (the one with the largest value in the frame_count array)
        if(!page_found) {
            int max_count = frame_count[0];
            int max_index = 0;
            for(k = 1; k < num_frames; k++) {
                if(frame_count[k] > max_count) {
                    max_count = frame_count[k];
                    max_index = k;
                }
            }
            frames[max_index] = page_number;
            frame_count[max_index] = i + 1;
            page_faults++;
        }

        // Print the current state of memory after each iteration
        printf("Memory at iteration %d: ", i + 1);
        for(j = 0; j < num_frames; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}

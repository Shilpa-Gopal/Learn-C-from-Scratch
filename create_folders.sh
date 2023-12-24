#!/bin/bash

# Create lessons and projects folders
mkdir lessons projects

# Loop to create lesson folders and initial README files
for lesson_number in {1..9}; do
  lesson_folder="lessons/lesson-$lesson_number"
  project_folder="projects/project-$lesson_number"
  
  mkdir -p "$lesson_folder" "$project_folder"

  # Create an initial README in lesson and project folders
  echo "# Lesson $lesson_number: Placeholder" > "$lesson_folder/README.md"
  echo "# Project $lesson_number: Placeholder" > "$project_folder/README.md"
done

# Create resources folder
mkdir resources

# Create the main README.md
echo "# Learn C++ from Scratch" > README.md
 

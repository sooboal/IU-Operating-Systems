#!/bin/bash

# do not forget chmod +x rename.sh before running the script!

BASE_DIR="$PWD"

for dir in "$BASE_DIR"/*; do
    if [ -d "$dir" ]; then
        dirname=$(basename "$dir")

        name_lastname_part="${dirname%%_*}"

        name_lastname=$(echo "$name_lastname_part" | tr ' ' '_')

        new_pdf_name="${name_lastname}.pdf"

        pdf_file=$(find "$dir" -maxdepth 1 -type f -iname "*.pdf" | head -n 1)

        if [ -n "$pdf_file" ]; then
            new_pdf_path="$dir/$new_pdf_name"
            mv "$pdf_file" "$new_pdf_path"
            echo "Renamed: $pdf_file -> $new_pdf_path"
        else
            echo "No PDF found in: $dir"
        fi
    fi
done


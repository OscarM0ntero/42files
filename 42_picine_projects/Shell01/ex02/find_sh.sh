find . -name "*.sh" | sed 's#.*/##' | rev | cut -c 4- | rev

#! /usr/bin/env bash

function die() {
    echo "$@" >&2
    exit 1
}

num_of_copies=
suffix=1

if [[ "$1" == "-h" ]] || [[ "$1" == "--help" ]]; then
    echo "Using: mcp [ARGS] NUMBER_OF_COPIES SOURCE DIRECTORY"
    echo "ARGUMENTS:"
    echo "-h, --help                          display this help and exit"
    echo "-s, --suffix [LETTER or NUMBER]     copy suffix will begin with this number or letter (only capital)"
    exit 0
elif [[ "$1" == "-s" ]] || [[ "$1" == "--suffix" ]]; then
    shift
    suffix="$1"
    shift
fi

if [[ "$1" =~ ^[0-9]+$ ]] && (( "$1" > 0 )); then
    num_of_copies=$1
    shift
else
    die "Wrong number of copies!"
fi

filepath="$1"
shift
destination="$1"
shift

if [[ !(-f $filepath) ]]; then
    die "'$filepath' is not a file"
fi

if [[ !(-d $destination) ]]; then
    mkdir "$destination"
fi

filename="$(basename "$filepath")"

for (( i=0; i<num_of_copies; i++ )); do
    if [[ "$suffix" =~ ^[0-9]+$ ]]; then
        cp "$filepath" "$destination"/"${filename%.*}"_"$suffix"."${filename#*.}"
        (( suffix++ ))
    elif [[ "$suffix" =~ ^[A-Z]+$ ]]; then
        cp "$filepath" "$destination"/"${filename%.*}"_"$suffix"."${filename#*.}"
        last_letter="$(tr '[A-YZ]' '[B-ZA]' <<< "${suffix:$((${#suffix}-1)):1}")"
        suffix=${suffix:0:$((${#suffix} - 1))}$last_letter
        if [[ "$last_letter" == "A" ]]; then
            suffix="$suffix"A
        fi
    else
        die "Wrong suffix!"
    fi 
done

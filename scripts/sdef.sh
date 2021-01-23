#!/bin/sh

APP_PATH=${1}
BASENAME=${2}

sdef "$APP_PATH" > "sdefs/$BASENAME.sdef"
sdef "$APP_PATH" | sdp -fh -N "$BASENAME" -o sdefs

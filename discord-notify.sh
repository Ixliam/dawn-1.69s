#!/bin/bash
message="$1"
## format to parse to curl
## echo Sending message: $message
msg_content=\"$message\"

## discord webhook
url='https://discordapp.com/api/webhooks/YOUR_SPECIAL_DISCORD_CODE_HERE'
curl -H "Content-Type: application/json" -X POST -d "{\"content\": $msg_content}" $url

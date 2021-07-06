#!/bin/bash
Recipent="hoanvc@vissoft.vn"
Subject="Test linux mail script"
Message="Hello Hoan"
`mail -s $Subject $Recipent <<< $Message`

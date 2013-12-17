function rc_while() {
  while read -n 1 _c; do
    rc "$_c"
  done
}

function rc() {
  _base_command='curl https://api.spark.io/v1/devices/'"$SPARK_CORE_DEVICE_ID"'/rccar -d access_token='"$SPARK_CORE_ACCESS_TOKEN"' -d "params=rc,__CMD__"'
  case "$1" in
  i) echo "FORWARD march!"
    _command=$(echo "${_base_command}" | sed 's/__CMD__/FORWARD/')
     ;;
  k) echo "Come on BACK now"
    _command=$(echo "${_base_command}" | sed 's/__CMD__/BACK/')
     ;;
  l) echo "Hang a LEFT"
    _command=$(echo "${_base_command}" | sed 's/__CMD__/LEFT/')
     ;;
  j) echo "Hang a RIGHT"
    _command=$(echo "${_base_command}" | sed 's/__CMD__/RIGHT/')
     ;;
  s) echo "STOP!"
    _command=$(echo "${_base_command}" | sed 's/__CMD__/STOP/')
     ;;
  *) echo "Don't know what to do with $1"
     return 1
     ;;
  esac

  echo $_command
  echo $_command | bash
  return 0
}

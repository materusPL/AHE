function Link(el)
  el.target = el.target:gsub(" ", "%%20")
  return el
end

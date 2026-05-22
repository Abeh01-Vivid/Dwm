# dwm — dynamic window manager
> **Theme:** Catppuccin Mocha · **Font:** JetBrains Mono Nerd Font · **Tags:** 一二三四五六七八九

A suckless [dwm](https://dwm.suckless.org/) configuration tuned for Void Linux + X11 with:
- Catppuccin Mocha colour scheme
- Kanji tag labels
- Vanitygaps patch (inner/outer gaps)
- Centered master layout patch
- Restart-in-place patch

---

## Required patches

Download and apply these patches **before** placing `config.h`:

| Patch | Purpose | URL |
|---|---|---|
| `vanitygaps` | Gaps + extra layouts | https://dwm.suckless.org/patches/vanitygaps/ |
| `centeredmaster` | Centered master layout | https://dwm.suckless.org/patches/centeredmaster/ |
| `restart` | `Mod+Ctrl+R` hot-restart | https://dwm.suckless.org/patches/restart/ |

Apply patches with:
```sh
patch -p1 < vanitygaps.diff
patch -p1 < centeredmaster.diff
patch -p1 < restart.diff
```

> Patch conflicts are common — resolve them manually in the `.rej` files, then re-run.

---

## Dependencies (Void Linux)

```sh
# Build tools
xbps-install -S base-devel libX11-devel libXft-devel libXinerama-devel

# Runtime
xbps-install -S st dmenu rofi pamixer brightnessctl scrot slock

# Fonts
xbps-install -S font-jetbrains-mono-nerd-fonts noto-fonts-emoji
```

---

## Build & install

```sh
git clone https://git.suckless.org/dwm
cd dwm

# Apply patches first (see above), then:
cp /path/to/config.h config.h

sudo make clean install
```

DWM installs to `/usr/local/bin/dwm` by default.

---

## Starting DWM

### With LightDM (existing setup)
Create an Xsession entry:
```sh
sudo tee /usr/share/xsessions/dwm.desktop <<'EOF'
[Desktop Entry]
Name=dwm
Comment=Dynamic window manager
Exec=dwm
Type=Application
EOF
```

Then select **dwm** from LightDM's session menu.

### With `~/.xinitrc` / `startx`
```sh
echo 'exec dwm' >> ~/.xinitrc
startx
```

### With a status bar (slstatus)
DWM reads the root window name for the status bar. Use `slstatus` or a shell script:

```sh
# Install slstatus (build from source — not in Void repos)
git clone https://tools.suckless.org/slstatus
cd slstatus && sudo make clean install

# Launch alongside dwm in .xinitrc:
slstatus &
exec dwm
```

Or a simple shell loop:
```sh
while true; do
    VOL=$(pamixer --get-volume-human)
    DATE=$(date '+%a %d %b  %H:%M')
    xsetroot -name "  $VOL    $DATE "
    sleep 5
done &
exec dwm
```

---

## Key bindings (quick reference)

| Keys | Action |
|---|---|
| `Mod + Shift + Return` | Open terminal (`st`) |
| `Mod + Space` | Rofi launcher |
| `Mod + p` | dmenu |
| `Mod + b` | Browser (Firefox) |
| `Mod + q` | Kill window |
| `Mod + j / k` | Focus next/prev window |
| `Mod + h / l` | Resize master area |
| `Mod + Return` | Promote to master |
| `Mod + t` | Tile layout |
| `Mod + f` | Floating layout |
| `Mod + m` | Monocle layout |
| `Mod + u` | Centered master layout |
| `Mod + Shift + Space` | Toggle floating |
| `Mod + Shift + = / -` | Increase/decrease gaps |
| `Mod + Shift + g` | Toggle gaps |
| `Mod + 1–9` | Switch to tag |
| `Mod + Shift + 1–9` | Move window to tag |
| `Mod + Ctrl + 1–9` | Toggle tag view |
| `Mod + , / .` | Focus prev/next monitor |
| `Mod + F12` | Toggle bar |
| `Mod + Shift + l` | Lock screen (slock) |
| `Mod + Shift + q` | Quit dwm |
| `Mod + Ctrl + r` | Restart dwm in place |
| `Print` | Region screenshot (scrot) |

**Mod key** = Super (Windows key)

---

## Autostart tips

Put anything you want launched at start before `exec dwm` in `~/.xinitrc`:

```sh
#!/bin/sh
# Compositor
picom --daemon

# Wallpaper
feh --bg-fill ~/Pictures/wallpaper.jpg

# Status bar
slstatus &

exec dwm
```

---

## Customising colours

All colours are defined as `#define` macros at the top of `config.h` using the full Catppuccin Mocha palette. Edit `colors[][]` to remap:
- `SchemeNorm` — unfocused windows / bar background
- `SchemeSel`  — focused window / active tag (currently Mauve `#cba6f7`)
- `SchemeTitle` — bar title area

After any change, rebuild:
```sh
sudo make clean install
```
Then restart dwm with `Mod + Ctrl + R`.

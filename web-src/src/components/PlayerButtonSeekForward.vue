<template>
  <a @click="seek" :disabled="disabled" v-if="visible">
    <span class="icon"><i class="mdi mdi-fast-forward" :class="icon_style"></i></span>
  </a>
</template>

<script>
import webapi from '@/webapi'

export default {
  name: 'PlayerButtonSeekForward',
  props: ['seek_ms', 'icon_style'],

  computed: {
    now_playing () {
      return this.$store.getters.now_playing
    },
    is_stopped () {
      return this.$store.state.player.state === 'stop'
    },
    disabled () {
      return !this.$store.state.queue || this.$store.state.queue.count <= 0 || this.is_stopped ||
          this.now_playing.data_kind === 'pipe'
    },
    visible () {
      return ['podcast', 'audiobook'].includes(this.now_playing.media_kind)
    }
  },

  methods: {
    seek: function () {
      if (!this.disabled) {
        webapi.player_seek(this.seek_ms)
      }
    }
  }
}
</script>
